#include <OneWire.h>
#include <EEPROM.h>

#define nullptr 0
#define _ASSERT(cond) {if(!(cond)) { Serial.print(F("{assert:'")); Serial.print(#cond); Serial.print("', line:"); Serial.print(__LINE__); Serial.print("}\n"); }}
float globalIon = 0;
float globalMedianIon = 0;

const char appVersion[] = "{version:1.2, lastupdate:'20180302', builddate:'" __DATE__ "', buildtime:'" __TIME__ "'}\n";
 
template<typename T, int N>
class CMedian
{
  T memory[N];
  bool bFirst{true};

public:
  void Push(T t)
  {
    if (bFirst)
    {
      for (byte i=0; i<N; i++)
        memory[i] = t;
      bFirst = false;
      return;
    } 

    for (byte i=1; i<N; i++)
      memory[i-1] = memory[i];
    memory[N-1] = t; 
  }

  T Get()
  {
    byte indices[N];
    for (byte i=0; i<N; i++)
      indices[i] = i;

    for (byte i=0; i<N; i++)
      for (byte j=i+1; j<N; j++)
        if (memory[indices[i]] > memory[indices[j]])
        {
          byte temp = indices[i];
          indices[i] = indices[j];
          indices[j] = temp;
        }  
     
     return memory[indices[N/2]];
  }

  T PushGet(T t)
  {
    Push(t);
    return Get();
  }

  void Dump()
  {
    Serial.print("median = ");
    for (byte i=0; i<N; i++)
    {
      Serial.print(" ");
      Serial.print(memory[i]);
    }
    Serial.print(" -> ");
    Serial.print(Get());    
    Serial.print("\n");
  }
};

class CLogicState
{
  CLogicState* m_pPrevState{nullptr};
  static CLogicState* m_pLastState;
  
public:
  CLogicState()
  {
    if (!m_pLastState)
    {
      m_pLastState = this;
    }
    else
    {
      CLogicState* pTemp = m_pLastState;
      m_pLastState = this;
      m_pPrevState = pTemp;
    }
  }

  static CLogicState* FindState(const char* name)
  {
    CLogicState* pState = m_pLastState;
    while (pState)
    {
      if (pState->Name() == name)
        return pState;
      pState = pState->m_pPrevState;
    }
    return nullptr;    
  }
  
  virtual char* Name() = 0;
  virtual void Enter() = 0;
  virtual void Do() = 0;
};

CLogicState* CLogicState::m_pLastState{nullptr};

class CStateMachine
{
public:
  void Do();
  void Goto(const char* name);
  void Error(const __FlashStringHelper* message);
  void Info(const __FlashStringHelper* message);
  
  CLogicState* m_pState {0};
  const char* m_pGotoState {"safe"};
} logic;

class CTimer
{
public:
  int secondsOn{0};
  int secondsOff{9999};

  void Update(bool b)
  {
    if (b)
    {
        secondsOff = 0;
      if (secondsOn < 9999)
        secondsOn++;
    } else 
    {
      secondsOn = 0;
      if (secondsOff < 9999)
        secondsOff++;
    }
  }
};

class CConfig
{
  static const unsigned int nConfigOffset;
  static const unsigned long nCheckToken;
  
private:
  unsigned long nToken{0};
  unsigned int nClassSize{0};

public:  
  float temperatureSetMin{55};
  float temperatureSetMax{60};
  float temperatureBodyMax{90};
  unsigned int postHeatPumpInterval{20*60};
  unsigned int initPumpInterval{1*60};
  unsigned int hotPumpInterval{5*60};
  unsigned int postHeatSleepInterval{30*60};

  // DS18S20 ma rozsah -55 do +125
  float minSafeTemp{-20};
  float maxSafeTemp{95};
  bool bNoPump{false};

  void test()
  {
    defaults();
    postHeatSleepInterval = 10*60;
    temperatureSetMin = 35.0f;
    temperatureSetMax = 40.0f;
    temperatureBodyMax = 45.0f;    
  }
  
  void dump()
  {
    Serial.print(F("{temperatureSetMin:"));
    Serial.print(temperatureSetMin);
    Serial.print(F(",temperatureSetMax:"));
    Serial.print(temperatureSetMax);
    Serial.print(F(",temperatureBodyMax:"));
    Serial.print(temperatureBodyMax);
    
    Serial.print(",postHeatPumpInterval:");
    Serial.print(postHeatPumpInterval);
    Serial.print(",initPumpInterval:");
    Serial.print(initPumpInterval);
    Serial.print(",hotPumpInterval:");
    Serial.print(hotPumpInterval);
    Serial.print(",postHeatSleepInterval:");
    Serial.print(postHeatSleepInterval);
    
    Serial.print(",minSafeTemp:");
    Serial.print(minSafeTemp);
    Serial.print(",maxSafeTemp:");
    Serial.print(maxSafeTemp);

    Serial.print(",noPump:");
    Serial.print(bNoPump);
    Serial.print("}");
  }
  
  bool set(char* cmd)
  {
    if (tryset(cmd, "min=", temperatureSetMin)) return true;
    if (tryset(cmd, "max=", temperatureSetMax)) return true;
    if (tryset(cmd, "bodymax=", temperatureBodyMax)) return true;
    if (tryset(cmd, "postpump=", postHeatPumpInterval)) return true;
    if (tryset(cmd, "initpump=", initPumpInterval)) return true;
    if (tryset(cmd, "hotpump=", hotPumpInterval)) return true;
    if (tryset(cmd, "postsleep=", postHeatSleepInterval)) return true;
    if (tryset(cmd, "safemin=", minSafeTemp)) return true;
    if (tryset(cmd, "safemax=", maxSafeTemp)) return true;
    if (tryset(cmd, "nopump=", bNoPump)) return true;
    return false;
  }
  
  void defaults()
  {
    *this = CConfig();
  }

  bool isValid()
  {
    if (nToken != nCheckToken)
      return false;

    if (nClassSize != sizeof(CConfig))
      return false;

    if (temperatureSetMin < 20 || temperatureSetMin > 100 ||
        temperatureSetMax < 20 || temperatureSetMax > 100 ||
        temperatureBodyMax < 20 || temperatureBodyMax > 110 ||
        temperatureSetMin > temperatureSetMax ||
        minSafeTemp < -40 || minSafeTemp > 120 ||
        maxSafeTemp < -40 || maxSafeTemp > 120 ||
        minSafeTemp > maxSafeTemp)
    {
      return false;
    }

    if (postHeatPumpInterval > 9000 || 
        initPumpInterval > 9000 ||
        hotPumpInterval > 9000 ||
        postHeatSleepInterval > 9000)
    {
      return false;    
    }

    if (bNoPump != false && bNoPump != true)
      return false;
      
    return true;
  }
    
  void load()
  {
    EEPROM.get(nConfigOffset, *this);
    
    if (!isValid())
    {
      Serial.print("{error:'read settings failed, resetting to defaults'}");
      defaults();
      _ASSERT(isValid());
      save();
    }
  }
  
  void save()
  {
    nToken = nCheckToken;
    nClassSize = sizeof(CConfig);
    
    EEPROM.put(nConfigOffset, *this);
  }
  
  template<typename T>
  bool tryset(char* cmd, const char* key, T& target)
  {
    byte l = strlen(key);
    if (strncmp(cmd, key, l) == 0)
    {
      target = (T)atoi(cmd+l);
      return true;
    }
    return false;    
  }  
} config;

const unsigned int CConfig::nConfigOffset{37};
const unsigned long CConfig::nCheckToken{'bla4'};

class CMachine
{
  static const float invalidTemperature = -999.0f;
  
public:
  enum EIon
  {
    Error,
    Hori,
    Nehori,
    Prechod,
    Vypnuty
  };

  enum EKlapka
  {
    Zatvorena=0,
    Otvorena=1
  };
  
  struct {
    bool ventilator{false};
    bool cerpadlo{false};
    bool zapalovanie{false};
    bool plyn{false};
    bool klapka{false};
  } sensorsOut;
  
  struct {
    EIon ion{Error};
    bool startStop{false};
    
    bool tlakPlynu{false};
    bool tlakVyfuku{false};
    bool preslah{false};
    bool ochranaCerpadlo{false};
    bool ochranaVentilator{false};
  } sensorsIn;

  struct {
    float vodaVstup{invalidTemperature};
    float vodaVystup{invalidTemperature};
    float kotol{invalidTemperature};
//    float vyfuk;
    float nasavanie{invalidTemperature};
  } temperatures;

  struct {
    CTimer ventilator;
    CTimer cerpadlo;
    CTimer zapalovanie;
    CTimer plyn;
    CTimer hori;
    CTimer klapka;
    unsigned long uptime{0};
    unsigned long plynSeconds{0};
    unsigned int heatCycles{0};
    unsigned int errors{0};
  } timers;
  
  bool AnyError()
  {
    // TODO: podmienka plyn & zapalovanie & nehori
    if (sensorsOut.plyn && sensorsIn.ion != Hori && timers.plyn.secondsOn >= 20)
    {
      if (sensorsIn.tlakPlynu)
      {
        logic.Error(F("Plyn spuseny bez zapalovania. Zavri plynovy ventil"));
        return true;
      }
    }
    
    if (sensorsOut.zapalovanie && timers.klapka.secondsOn < 36)
    {
      logic.Error(F("Klapka este zavreta"));
      return true;      
    }
    
    if (timers.zapalovanie.secondsOn >= 10)
    {
      logic.Error(F("Zapalovanie zapnute prilis dlho"));
      return true;
    }

    if (!sensorsIn.tlakPlynu)
    {
      logic.Error(F("Tlak plynu na vstupe nespravny"));
      return true;
    }
    if (!sensorsIn.tlakVyfuku)
    {
      logic.Error(F("Upchaty vyfuk"));
      return true;
    }
    if (!sensorsIn.preslah)
    {
      logic.Error(F("Preslahovy senzor hlasi chybu"));
      return true;
    }
    if (!sensorsIn.ochranaCerpadlo ||
        !sensorsIn.ochranaVentilator)
    {
      logic.Error(F("Nadprudove ochrany hlasia chybu"));
      return true;
    }
    if (timers.uptime>3)
    {     
      if (!safeTemp(temperatures.vodaVystup) ||
          !safeTemp(temperatures.vodaVstup) ||
          !safeTemp(temperatures.kotol) ||
          !safeTemp(temperatures.nasavanie) )
      {
        logic.Error(F("Nepodarili sa odmerat teploty, alebo teplota mimo rozsahu"));
        return true;
      }
    }  
    return false;  
  }

  bool safeTemp(float t)
  {
    if (t == invalidTemperature)
      return false;
      
    if (t < config.minSafeTemp)
      return false;
      
    if (t > config.maxSafeTemp)
      return false;

    return true;
  }
  
  void Update1s()
  {
    timers.ventilator.Update(sensorsOut.ventilator);
    timers.cerpadlo.Update(sensorsOut.cerpadlo);
    timers.zapalovanie.Update(sensorsOut.zapalovanie);
    timers.plyn.Update(sensorsOut.plyn);
    timers.hori.Update(sensorsIn.ion == Hori);
    timers.klapka.Update(sensorsOut.klapka);
    timers.uptime++;
    if (sensorsOut.plyn)
        timers.plynSeconds++;

    Serial.print("{state:'");
    Serial.print(logic.m_pState->Name());
    Serial.print("',ion:[");
    Serial.print(globalIon);
    Serial.print(",'");
    switch (sensorsIn.ion)
    {
      case Error: Serial.print(F("Error")); break;
      case Hori: Serial.print(F("Hori")); break;
      case Nehori: Serial.print(F("Nehori")); break;
      case Prechod: Serial.print(F("Prechod")); break;
      case Vypnuty: Serial.print(F("Vypnuty")); break;
    }
    Serial.print("'],temp:{");

    Serial.print(F("vstup:"));
    printTemp(temperatures.vodaVstup);
    Serial.print(F(",vystup:"));
    printTemp(temperatures.vodaVystup);
    Serial.print(F(",termostat:"));
    printTemp(temperatures.kotol);
    Serial.print(F(",vzduch:"));
    printTemp(temperatures.nasavanie);
    Serial.print(F("},errors:["));
    
    if (!sensorsIn.tlakPlynu)
       Serial.print(F("'plynVstup',"));
    if (!sensorsIn.tlakVyfuku)
       Serial.print(F("'tlakVyfuku',"));
    if (!sensorsIn.preslah)
       Serial.print(F("'preslah',"));
    if (!sensorsIn.ochranaCerpadlo || !sensorsIn.ochranaVentilator)
       Serial.print(F("'ochrana',"));

    Serial.print(F("],devs:{"));

    Serial.print(F("cerpadlo:"));
    Serial.print(sensorsOut.cerpadlo ? "'on'" : "'off'");
    Serial.print(F(",ventilator:"));
    Serial.print(sensorsOut.ventilator ? "'on'" : "'off'");
    Serial.print(F(",zapalovanie:"));
    Serial.print(sensorsOut.zapalovanie ? "'on'" : "'off'");
    Serial.print(F(",plyn:"));
    Serial.print(sensorsOut.plyn ? "'ON'" : "'off'");
    Serial.print(F(",klapka:"));
    if (timers.klapka.secondsOn >= 36)
      Serial.print(F("'otvorena'"));
    else if (timers.klapka.secondsOff >= 36)
      Serial.print(F("'ZATVORENA'"));
    else if (sensorsOut.klapka == CMachine::Otvorena)
      Serial.print(F("'OTVARA SA'"));
    else if (sensorsOut.klapka == CMachine::Zatvorena)
      Serial.print(F("'ZATVARA SA'"));
    Serial.print(F("}}\n"));
  }

  void printTemp(float t)
  {
    if (t != invalidTemperature)
      Serial.print(t);
    else
      Serial.print(F("'error'"));
  }
  
  void Update10s()
  {
    Serial.print(F("{uptime:"));
    Serial.print(timers.uptime);
    Serial.print(F(",config:"));
    config.dump();
    Serial.print(",errors:");
    Serial.print(timers.errors);
    Serial.print(",cycles:");
    Serial.print(timers.heatCycles);
    Serial.print(",plynSeconds:");
    Serial.print(timers.plynSeconds);
    Serial.print("}\n");    
  }
  
} machine;

class CLogicStateSafe : public CLogicState
{
public:
  virtual char* Name() override
  {
    return "safe";
  }

  virtual void Enter() override
  {
    m_bCerpadloIdle = false;
    // TODO: preco tu bol && m_bStartup ??  // !false && false = false
    m_bVentilatorIdle = !machine.sensorsOut.ventilator /*&& m_bStartup*/;
    machine.timers.ventilator.secondsOn = 0;

    m_nCerpadloInterval = config.initPumpInterval;
    
    machine.sensorsOut.plyn = false;
    machine.sensorsOut.zapalovanie = false;
    machine.sensorsOut.klapka = CMachine::Zatvorena;
    
    m_bStartup = false;
  }

  virtual void Do() override
  {
    if (JeMiTeplo())
      m_nCerpadloInterval = config.hotPumpInterval;
      
    DobehCerpadla(m_bCerpadloIdle, m_nCerpadloInterval);
    DobehVentilatora(m_bVentilatorIdle, 30);

    if (machine.sensorsIn.startStop)
    {
      if (machine.AnyError())
      {
        logic.Error(F("porucha vstupneho senzora alebo teplomera"));
      } else
      {
        if (IsFinished())
          logic.Goto("automatic-prepare");
        else
          logic.Error(F("Prebieha 30s interval vyfukovania spalin"));
      }
    }
  }

  bool IsFinished() 
  {
    return m_bVentilatorIdle;
  }

  static void DobehVentilatora(bool& bVentilatorIdle, int nTime)
  {
    machine.sensorsOut.ventilator = !bVentilatorIdle;
    
    if (!bVentilatorIdle)
    {
        bVentilatorIdle = machine.timers.ventilator.secondsOn >= nTime;
    }  
  }
  
  static void DobehCerpadla(bool& bCerpadloIdle, int nTime)
  {
    if (CerpadloShouldRun())
    {
      bCerpadloIdle = false;
      machine.sensorsOut.cerpadlo = true;
      machine.timers.cerpadlo.secondsOn = 0;
    } else
    {
      if (!bCerpadloIdle)
        bCerpadloIdle = machine.timers.cerpadlo.secondsOn >= nTime;
      
      machine.sensorsOut.cerpadlo = !bCerpadloIdle;
    }    
  }

  static bool JeMiTeplo()
  {
    if (machine.temperatures.vodaVystup >= 30.0f ||
        machine.temperatures.vodaVstup >= 30.0f ||
        machine.temperatures.kotol >= 30.0f)
      return true;

    return false;
  }
  
  static bool CerpadloShouldRun()
  {
    if (machine.AnyError())
      return true;
      
    if (JeMiTeplo())
      return true;

    if (abs(machine.temperatures.vodaVystup - machine.temperatures.vodaVstup) > 10.0f)
      return true;

    // 20 min po kureni vynut cerpadlo
    if (machine.timers.hori.secondsOff < config.postHeatPumpInterval || machine.timers.plyn.secondsOff < config.postHeatPumpInterval)
      return true;

    return false;
  }
  
  bool m_bCerpadloIdle {false};
  bool m_bVentilatorIdle {false};
  bool m_bStartup {true};
  int m_nCerpadloInterval{60};
} stateSafe;

class CStateAutomaticStandby : public CLogicState
{
public:
  virtual char* Name() override
  {
    return "automatic-standby";
  }

  virtual void Enter() override
  {
    m_bCerpadloIdle = false;
    m_bVentilatorIdle = false; //!machine.sensorsOut.ventilator;
    
    machine.sensorsOut.plyn = false;
    machine.sensorsOut.zapalovanie = false;
    machine.sensorsOut.klapka = CMachine::Zatvorena; // zatvor klapku, tu otvarame az ked ideme kurit

    machine.timers.ventilator.secondsOn = 0;
    
  }

  virtual void Do() override
  {
    // v Dobeh cerpadla uz je implementovany post heat interval,
    // ale ked teplota znova vystupa nad 30, spustame dlhy interval
    CLogicStateSafe::DobehCerpadla(m_bCerpadloIdle, config.hotPumpInterval); 
    
    // TODO: chybal dobeh ventilatora
    CLogicStateSafe::DobehVentilatora(m_bVentilatorIdle, 30);

    if (machine.sensorsIn.startStop)
    {      
      if (!m_bVentilatorIdle)
      {
        logic.Info(F("Vyfukujem spaliny"));
      } else
      if (ShouldStopHeat())
      {
        logic.Info(F("Najprv musim vychladnut"));
      } else
      {
        logic.Goto("automatic-prepare");
      }
      return;
    }
    
    // musi pockat kym prejde aspon 30 min pred tym nez znova zapne
    if (machine.timers.hori.secondsOff < config.postHeatSleepInterval || machine.timers.plyn.secondsOff < config.postHeatSleepInterval)
      return;

    if (ShouldStartHeat())
      logic.Goto("automatic-prepare");
  }

  static bool ShouldStartHeat()
  {
    // 5 stupnova hystereza proti oscilaciam
    if (machine.temperatures.kotol > config.temperatureBodyMax-5.0f)
      return false;
      
    return max(machine.temperatures.vodaVstup, machine.temperatures.vodaVystup) <= config.temperatureSetMin; 
  }
  
  static bool ShouldStopHeat()
  {
    if (machine.temperatures.kotol > config.temperatureBodyMax)
      return true;
    return max(machine.temperatures.vodaVstup, machine.temperatures.vodaVystup) > config.temperatureSetMax; 
  }
  
  bool m_bCerpadloIdle;
  bool m_bVentilatorIdle;
} stateAutomaticStandby;

class : public CLogicState
{
public:
  virtual char* Name() override
  {
    return "automatic-prepare";
  }

  virtual void Enter() override
  {
    _ASSERT(CStateAutomaticStandby::ShouldStartHeat());
    
    machine.sensorsOut.cerpadlo = true;
    machine.sensorsOut.ventilator = true;
    // TODO: vymazat pocitadlo klapky?
    machine.timers.klapka.secondsOn = 0;
    machine.sensorsOut.klapka = CMachine::Otvorena;
  }

  virtual void Do() override
  {
    if (machine.sensorsIn.startStop)
    {
      // mozeme zastavit ventilator, zatial nic nerobil
      machine.sensorsOut.ventilator = false;
      logic.Goto("safe");
      return;
    }

    if (machine.timers.klapka.secondsOn >= 3)
    {
      // Zeby ventilator sposobil pokles napatia?
      // 4.16, 4.03    
      if (machine.sensorsIn.ion != CMachine::Nehori)
      {
        logic.Error(F("Nemozem spustit zapalovanie kvoli ionizacnemu senzoru"));
        Serial.print(F("{ion:"));
        Serial.print(globalIon);
        Serial.print(F(",median:"));
        Serial.print(globalMedianIon);
        Serial.print(F(",time:"));
        Serial.print(machine.timers.klapka.secondsOn);
        Serial.print(F("}\n"));
        return;      
      }
    }
        
    if (machine.timers.cerpadlo.secondsOn >= 10 && 
        machine.timers.ventilator.secondsOn >= 30 &&
        machine.timers.klapka.secondsOn >= 36)
    {
      logic.Goto("automatic-ignition");
      return;
    }
  }
} stateAutomaticPrepare;

class : public CLogicState
{
public:
  virtual char* Name() override
  {
    return "automatic-ignition";
  }

  virtual void Enter() override
  {
    _ASSERT(machine.sensorsIn.ion == CMachine::Nehori);

    machine.sensorsOut.plyn = true;
    machine.sensorsOut.zapalovanie = true;
    machine.timers.zapalovanie.secondsOn = 0;
    machine.timers.zapalovanie.secondsOff = 0;
    machine.timers.heatCycles++;
  }

  virtual void Do() override
  {
    if (machine.sensorsIn.startStop)
    {
      machine.sensorsOut.zapalovanie = false;
      machine.sensorsOut.plyn = false;

      logic.Goto("safe");
      return;
    }

    // v lete stacia 2 sekundy, ked je zima je to malo
    if ( machine.timers.hori.secondsOn >= 4)
    {
      // TODO: skontrolovat, zda sa ze vypne 4 sekundy od zaciatku zapalovania,
      // resp od prechodu
      if (machine.sensorsOut.zapalovanie)
        logic.Info(F("Hori 4 sekundy, vypinam zapalovanie"));
        
      machine.sensorsOut.zapalovanie = false;
    }

    if (!machine.sensorsOut.zapalovanie)
    {
      // ak uz dozapaloval cakame na rozhorenie
      if (machine.sensorsIn.ion != CMachine::Hori && machine.sensorsIn.ion != CMachine::Prechod)
      {
        logic.Error(F("Nepodaril sa zapalit plamen"));
        return;
      }
    }
        
    if (machine.timers.hori.secondsOn >= 10)
    {
      logic.Info(F("Plamen vydrzal stabilny 10 seknud"));
      logic.Goto("automatic-burning");
      return;
    }
    
    // je v prechode, iskra zrusena, cakame kym sa rozhori
    if (machine.timers.zapalovanie.secondsOff >= 30)
    {
      logic.Error(F("Nepodaril sa zapalit plamen, stale v prechode"));
      return;
    }

    if (machine.sensorsOut.zapalovanie)
    {
      if (machine.timers.zapalovanie.secondsOn >= 5)
      {
        machine.sensorsOut.zapalovanie = false;
      }
    }
  }
} stateAutomaticIngition;

class : public CLogicState
{
public:
  virtual char* Name() override
  {
    return "automatic-burning";
  }

  virtual void Enter() override
  {
  }

  virtual void Do() override
  {
    if (machine.sensorsIn.startStop)
    {
      logic.Goto("safe");
      return;
    }
        
    if (machine.sensorsIn.ion != CMachine::Hori)
    {
      Serial.print("{debug:'");
      Serial.print("globalMedianIon=");
      Serial.print(globalMedianIon);
      Serial.print(" globalIon=");
      Serial.print(globalIon);
      Serial.print("'}\n");
      logic.Error(F("Zhasol plamen"));
      return;
    }
    
    if (CStateAutomaticStandby::ShouldStopHeat())
    {
      logic.Goto("automatic-standby");
    }
  }
} stateAutomaticBurning;

class : public CLogicState
{
public:
  virtual char* Name() override
  {
    return "manual";
  }

  virtual void Enter() override
  {
  }

  virtual void Do() override
  {
    if (machine.sensorsIn.startStop)
    {
      logic.Goto("safe");
      return;
    }
  }
} stateManual;

class : public CLogicState
{
public:
  virtual char* Name() override
  {
    return "locked";
  }

  virtual void Enter() override
  {
  }

  virtual void Do() override
  {
  }
} stateLocked;

void CStateMachine::Do()
{
  if (m_pGotoState)
  {
    Serial.print("{state:'");
    Serial.print(m_pState ? m_pState->Name() : "startup");
    Serial.print("',goto:'");
    Serial.print(m_pGotoState);
    Serial.print("'}\n");
    
    CLogicState* pState = CLogicState::FindState(m_pGotoState);
    
    m_pGotoState = nullptr;
    _ASSERT(pState);
  
    if (!pState)
      pState = CLogicState::FindState("safe");
    
    if (pState)
    {
      pState->Enter();
      m_pState = pState;

      if (m_pState->Name() != "locked" && machine.AnyError())
      {
        Goto("safe");
        return;
      }
    }
  }
  
  m_pState->Do();
  if (m_pState->Name() == "locked")
    return;
    
  if (machine.AnyError() && m_pState->Name() != "safe")
    Goto("safe");
}

void CStateMachine::Error(const __FlashStringHelper* message)
{
  // TODO: oplati sa nam zahltit cely vystup?
  // vypis
  machine.timers.errors++;
  Serial.print(F("{state:'"));
  Serial.print(m_pState->Name());
  Serial.print(F("',error:'"));
  Serial.print(message);
  Serial.print(F("'}\n"));
  
  if (m_pState->Name() != "safe")
  {
    Goto("safe");
  }
  else
  {
    // Uz sme v safe mode, vsetko je vypnute, redukujeme chybove hlasky
    delay(500);
  }
}

void CStateMachine::Info(const __FlashStringHelper* message)
{
  // vypis
  Serial.print(F("{state:'"));
  Serial.print(m_pState->Name());
  Serial.print(F("',info:'"));
  Serial.print(message);
  Serial.print(F("'}\n"));
}

void CStateMachine::Goto(const char* name)
{
  if (name == m_pState->Name())
    return;
    
  m_pGotoState = name;
}

OneWire oneWire(A4); // nPinTeplomer

class CHardware
{
private:
  static const byte nPinOutObehoveCerpadlo = 4; // oranzovy_
  static const byte nPinOutVentilator = 5; // oranzovy
  static const byte nPinOutPlyn = 6; // zeleny_
  static const byte nPinOutZapalovanie = 7; // zeleny
  static const byte nPinOutServoKlapky = 3; // hnedy_

  static const byte nPinInStartStop = 8; // zeleny HT/ start stop
  static const byte nPinInPreslah = 9; // zeleny_ PZS
  static const byte nPinInTlakSpalin = 10; // oranzovy MSP
  static const byte nPinInTlakPlynu = 11; // oranzovy_ MPL
  static const byte nPinInOchrany = 12; // hnedy_ R100A 1/2
 
  static const byte nPinInIonizacnySenzor = A5;
  static const byte nPinTeplomer = A4;

private:
  struct Status
  {
    byte outObehoveCerpadlo{0};
    byte outVentilator{0};
    byte outPlyn{0};
    byte outZapalovanie{0};
    byte outServoKlapky{0};

    byte inStartStop{0};
    byte inPreslah{0};
    byte inTlakSpalin{0};
    byte inTlakPlynu{0};  
    byte inOchrany{0};

    uint16_t inIonizacnySenzor{0};

    float vodaVstup;
    float vodaVystup;
    float termostat;
    float nasavanie;
  };

  struct Status status;
  byte nStartStopDebounce{2};

public:
  void Init()
  {
    Serial.begin(9600);
    Serial.print(F("{message:'Startujem kontroler kotla ORK100...'}\n"));
    Serial.print(appVersion);

    pinMode(nPinOutObehoveCerpadlo, OUTPUT);
    digitalWrite(nPinOutObehoveCerpadlo, 0);
    pinMode(nPinOutVentilator, OUTPUT);
    digitalWrite(nPinOutVentilator, 0);
    pinMode(nPinOutPlyn, OUTPUT);
    digitalWrite(nPinOutPlyn, 0);
    pinMode(nPinOutZapalovanie, OUTPUT);
    digitalWrite(nPinOutZapalovanie, 0);
    pinMode(nPinOutServoKlapky, OUTPUT);
    digitalWrite(nPinOutServoKlapky, 0); 

    pinMode(nPinInStartStop, INPUT_PULLUP);
    pinMode(nPinInPreslah, INPUT_PULLUP);
    pinMode(nPinInTlakSpalin, INPUT_PULLUP);
    pinMode(nPinInTlakPlynu, INPUT_PULLUP);
    pinMode(nPinInOchrany, INPUT_PULLUP);

    pinMode(nPinInIonizacnySenzor, INPUT);
  }

  void UpdateOutput(struct Status& status)
  {
    digitalWrite(nPinOutObehoveCerpadlo, status.outObehoveCerpadlo);
    digitalWrite(nPinOutVentilator, status.outVentilator);
    digitalWrite(nPinOutPlyn, status.outPlyn);
    digitalWrite(nPinOutZapalovanie, status.outZapalovanie);
    digitalWrite(nPinOutServoKlapky, status.outServoKlapky);
  }

  void UpdateInput(struct Status& status)
  {
//    status.inHlavnyTeplomer = !digitalRead(nPinInHlavnyTeplomer);
    status.inStartStop = !digitalRead(nPinInStartStop);
    status.inPreslah = !digitalRead(nPinInPreslah);
    status.inTlakSpalin = !digitalRead(nPinInTlakSpalin);
    status.inTlakPlynu = !digitalRead(nPinInTlakPlynu);
    status.inOchrany = !digitalRead(nPinInOchrany);

    status.inIonizacnySenzor = analogRead(nPinInIonizacnySenzor);
  }

  void Update()
  {
    UpdateInput(status);

    static CMedian<byte, 5> medStartStop;

    medStartStop.Push(status.inStartStop);
    if (medStartStop.Get() && nStartStopDebounce == 0)
    {
      machine.sensorsIn.startStop = true;
      nStartStopDebounce = 2;
    }
    else
      machine.sensorsIn.startStop = false;

    static CMedian<byte, 5> medPlyn;
    static CMedian<byte, 5> medVyfuk;
    static CMedian<byte, 5> medPreslah;
    static CMedian<byte, 5> medOchranaCerpadlo;
    static CMedian<byte, 5> medOchranaVentilator;
    
    machine.sensorsIn.tlakPlynu = medPlyn.PushGet(status.inTlakPlynu);
    machine.sensorsIn.tlakVyfuku = medVyfuk.PushGet(status.inTlakSpalin);
    machine.sensorsIn.preslah = medPreslah.PushGet(status.inPreslah);
    machine.sensorsIn.ochranaCerpadlo = medOchranaCerpadlo.PushGet(status.inOchrany);
    machine.sensorsIn.ochranaVentilator = medOchranaVentilator.PushGet(status.inOchrany);
    machine.sensorsIn.ion = CMachine::Error;

    globalIon = status.inIonizacnySenzor*5.0f/1024.0f;

    static CMachine::EIon prevIon(CMachine::Error);
    static float prevIonVolts(0);
    
    static CMedian<int, 5> medianIon;
    medianIon.Push(status.inIonizacnySenzor);
    //medianIon.Dump();
    float ionVolts = medianIon.Get()*5.0f/1024.0f;

    globalMedianIon = ionVolts;
    
    if (ionVolts >= 4.2 /*&& ionVolts <= 4.95f*/)
      machine.sensorsIn.ion = CMachine::Nehori;
    if (ionVolts <= 0.5f)
      machine.sensorsIn.ion = CMachine::Vypnuty;
    // v zime klesa pod 1.0, povodne 1.0
    if (ionVolts >= 0.55f && ionVolts <= 3.3f)
      machine.sensorsIn.ion = CMachine::Hori;
      // v zime posunute z 3.2 na 3.3
    if (ionVolts >= 3.3f && ionVolts <= 4.2f)
      machine.sensorsIn.ion = CMachine::Prechod;


    if (prevIon != machine.sensorsIn.ion)
    {
      Serial.print("{debug:'");
      Serial.print("prevIonEnum:");
      /* Error, Hori, Nehori, Prechod, Vypnuty */
      Serial.print(prevIon);
      Serial.print(" prevIonVolts:");
      Serial.print(prevIonVolts);
      Serial.print(" curIonEnum:");
      Serial.print(machine.sensorsIn.ion);
      Serial.print(" curIonVolts:");
      Serial.print(ionVolts);
      Serial.print("'}\n");      
    }
    prevIonVolts = ionVolts;
    prevIon = machine.sensorsIn.ion;
    
    // zapracuj aj vystup z nadprudovej ochrany
    status.outVentilator = machine.sensorsIn.ochranaVentilator && machine.sensorsOut.ventilator;
    status.outObehoveCerpadlo = machine.sensorsIn.ochranaCerpadlo && machine.sensorsOut.cerpadlo && (!config.bNoPump);
    status.outZapalovanie = machine.sensorsOut.zapalovanie; 
    status.outPlyn = machine.sensorsOut.plyn;
    status.outServoKlapky = machine.sensorsOut.klapka;

    UpdateOutput(status);
  }

  void Update1s()
  {
    if (nStartStopDebounce > 0)
      nStartStopDebounce--;

    if (status.outZapalovanie)
      return;
      
    UpdateTemperatures(status);    
    machine.temperatures.vodaVstup = status.vodaVstup;
    machine.temperatures.vodaVystup = status.vodaVystup;
    machine.temperatures.nasavanie = status.nasavanie;
    machine.temperatures.kotol = status.termostat;
  }
  
  float dallasTemperature(uint8_t* deviceAddress, uint8_t* scratchPad)
  {
    typedef enum {
      // Model IDs
      DS18S20MODEL =0x10,
      DS18B20MODEL =0x28,
      DS1822MODEL  =0x22,
      // Scratchpad locations
      TEMP_LSB        =0,
      TEMP_MSB        =1,
      HIGH_ALARM_TEMP =2,
      LOW_ALARM_TEMP  =3,
      CONFIGURATION   =4,
      INTERNAL_BYTE   =5,
      COUNT_REMAIN    =6,
      COUNT_PER_C     =7,
      SCRATCHPAD_CRC  =8,
      // Device resolution
      TEMP_9_BIT  =0x1F, //  9 bit
      TEMP_10_BIT =0x3F, // 10 bit
      TEMP_11_BIT =0x5F, // 11 bit
      TEMP_12_BIT =0x7F, // 12 bit
    };
    
    int16_t rawTemperature = (((int16_t)scratchPad[TEMP_MSB]) << 8) | scratchPad[TEMP_LSB];
  
    switch (deviceAddress[0])
    {
      case DS18B20MODEL:
      case DS1822MODEL:
        switch (scratchPad[CONFIGURATION])
        {
          case TEMP_12_BIT:
            return (float)rawTemperature * 0.0625;
          case TEMP_11_BIT:
            return (float)(rawTemperature >> 1) * 0.125;
          case TEMP_10_BIT:
            return (float)(rawTemperature >> 2) * 0.25;
          case TEMP_9_BIT:
            return (float)(rawTemperature >> 3) * 0.5;
        }
        break;
      case DS18S20MODEL:
        // Good spot. Thanks Nic Johns for your contribution
        return (float)(rawTemperature >> 1) - 0.25 +((float)(scratchPad[COUNT_PER_C] - scratchPad[COUNT_REMAIN]) / (float)scratchPad[COUNT_PER_C] );
    }
    return -999.0f;
  }

  void UpdateTemperatures(struct Status& status)
  { 
    float fTempHlavnyTermostat = -999.0f;
    float fTempVodaVstup = -999.0f;
    float fTempVodaVystup = -999.0f;
    float fTempNasavanie = -999.0f;

    typedef uint8_t DeviceAddress[8];
    
    typedef enum {
      STARTCONVO = 0x44,  // Tells device to take a temperature reading and put it on the scratchpad
      READSCRATCH = 0xBE,  // Read EEPROM
    };

    typedef enum {
      HlavnyTermostat = 0x96,
      VodaVstup = 0x16,
      Vyfuk = 0xa5,
      Vzduch = 0x50,
      VodaVystup = 0xc5
    };    
    
    // scan bus
    DeviceAddress deviceAddress;
    byte scratchpad[10];
    
    oneWire.reset_search();
    while (oneWire.search(deviceAddress))
    {
      if (oneWire.crc8(deviceAddress, 7) == deviceAddress[7]) // valid address
      {                
        oneWire.reset();
        oneWire.select(deviceAddress);
        oneWire.write(READSCRATCH);
        
        for (byte i=0; i<9; i++)
          scratchpad[i] = oneWire.read();

        float fTemperature = dallasTemperature(deviceAddress, scratchpad);
        oneWire.reset();

        // TODO: unsafe
        //if (fTemperature != 85.0f)
        //{
          switch (deviceAddress[7])
          {
            case HlavnyTermostat: fTempHlavnyTermostat = fTemperature; break;
            case VodaVstup: fTempVodaVstup = fTemperature; break;
            case VodaVystup: fTempVodaVystup = fTemperature; break;
            case Vzduch: fTempNasavanie = fTemperature; break;
          }        
        //}
      }
    }

    // request conversion
    oneWire.skip();
    oneWire.write(STARTCONVO);

    static CMedian<float, 5> medTermostat;
    static CMedian<float, 5> medVodaVstup;
    static CMedian<float, 5> medVodaVystup;
    static CMedian<float, 5> medNasavanie;

    status.termostat = medTermostat.PushGet(fTempHlavnyTermostat);
    status.vodaVstup = medVodaVstup.PushGet(fTempVodaVstup);
    status.vodaVystup = medVodaVystup.PushGet(fTempVodaVystup);
    status.nasavanie = medNasavanie.PushGet(fTempNasavanie);
  }
} hardware;

void ProcessInput(char ch)
{
  static char strBuf[16];
  static int nBufIndex = 0;

  if (logic.m_pState->Name() == "manual")
  {
    EvalManual(ch);
    return;
  }
  
  if (ch==0x0d || ch==0x0a)
  {
    if (nBufIndex > 0 && nBufIndex != 16)
    {
      strBuf[nBufIndex] = 0;
      Eval(strBuf);
    }
    
    nBufIndex = 0;    
  } else
  {
    if (nBufIndex < 16)
    {
      strBuf[nBufIndex++] = ch;
      
      if (nBufIndex == 16)
        logic.Info(F("Read buffer overflow"));      
    }
  }
}

void EvalManual(char ch)
{
  switch (ch)
  {
    case 'C': machine.sensorsOut.cerpadlo = 1; return;
    case 'c': machine.sensorsOut.cerpadlo = 0; break;
    case 'V': machine.sensorsOut.ventilator = 1; break;
    case 'v': machine.sensorsOut.ventilator = 0; break;
    case 'P': machine.sensorsOut.plyn = 1; break;
    case 'p': machine.sensorsOut.plyn = 0; break;
    case 'Z': machine.sensorsOut.zapalovanie = 1; break;
    case 'z': machine.sensorsOut.zapalovanie = 0; break;
    case 'K': machine.sensorsOut.klapka = 1; break;
    case 'k': machine.sensorsOut.klapka = 0; break;
    case 's': logic.Goto("safe"); break;
    case 'l': logic.Goto("locked"); break;
    
    case 0x0d:
    case 0x0a:
      break;
    default:
      logic.Error(F("Invalid character in manual mode"));
  } 
}

void Eval(char* cmd)
{
  if (strcmp(cmd, "stop") == 0)
  {
    if (logic.m_pState->Name() == "safe")
    {
      logic.Info(F("Uz je zastaveny"));
    } else
      logic.Goto("safe");
    return;
  }
  
  if (strcmp(cmd, "start") == 0)
  {
    if (logic.m_pState->Name() == "safe" || logic.m_pState->Name() == "automatic-standby")
    {
      machine.sensorsIn.startStop = true;
    } else 
    {
      logic.Info(F("V tomto stave nie je mozne spustit"));
    }
    return;
  }

  if (strcmp(cmd, "press") == 0)
  {
    machine.sensorsIn.startStop = true;
    return;    
  }
  
  if (strcmp(cmd, "safe") == 0)
  {
    logic.Goto("safe");
    return;
  }

  if (strcmp(cmd, "manual") == 0)
  {
    logic.Goto("manual");
    return;
  }

  if (strcmp(cmd, "locked") == 0)
  {
    logic.Goto("locked");
    return;
  }

  if (config.set(cmd))
    return;

  if (strcmp(cmd, "save") == 0)
  {
    if (config.isValid())
    {
      config.save();
      logic.Info(F("Config saved"));
    }
    else
      logic.Info(F("Incorrect config values"));
    return;
  }

  if (strcmp(cmd, "test") == 0)
  {
    config.test();
    return;
  }
  
  if (strcmp(cmd, "reset") == 0)
  {
    config.defaults();
    config.save();
    return;
  }

  if (strcmp(cmd, "info") == 0)
  {
    Serial.print(appVersion);
    return;
  }

  if (strcmp(cmd, "help") == 0)
  {
    logic.Info(F("https://gist.github.com/gabonator/f7cbc1fd3ac79a7fbc09c8d8922bb457"));
    logic.Info(F("commands: help, info, start, stop, safe, manual, help, min=, max=, save, reset, test, locked, press"));    
    return;
  }
  
  logic.Info(F("Unknown command"));
}

void setup() 
{
  hardware.Init();
  config.load();
}

void loop() 
{
  static unsigned long lLastMillis1s = 0;
  static unsigned long lLastMillis10s = 0;
  unsigned long lMillis = millis();

  hardware.Update();

  if (lMillis - lLastMillis1s >= 1000)
  {
    lLastMillis1s += 1000; 
    hardware.Update1s();
    machine.Update1s();    
  }

  if (lMillis - lLastMillis10s >= 10000)
  {
    lLastMillis10s += 10000;
    machine.Update10s();    
  }

  while (Serial.available())
  {
    ProcessInput(Serial.read());
  }
  
  if (machine.sensorsIn.startStop)
  {
    logic.Info(F("Start-stop signal received"));
  }
  logic.Do();    
}
