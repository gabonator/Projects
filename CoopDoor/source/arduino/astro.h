#include <math.h>
#include <stdint.h>

#define PI M_PI
//#define float double

class CAstro
{
public:
  struct State_t 
  {
    float phase; // 0..360: ["spring", "summer", "autumn", "winter"][phase/90]
    float daylen;
    float sunrise;
    float sunset;
    float time;    
  };

  struct Date_t
  {
    int16_t year;
    int8_t month;
    int8_t day;
  };

  struct Pos_t
  {
    float lat;
    float lon;
  };

  struct Time_t
  {
    int8_t hour;
    int8_t minute;
  };
 
  enum class EDayNight {
    Unknown,
    PolarNight,
    PolarDay,
    Night,
    Day
  };
  
  const char* GetState(EDayNight e)
  {
    static const char* states[] = {"Unknown", 
      "PolarNight", "PolarDay", "Night", "Day"};
    return states[(int)e];
  }

  State_t Sunrise(const Date_t& date, const Pos_t& pos)
  {
    const float RADS = PI/180.0f;
    const float DEGS = 180.0f/PI;

    float days = SunriseDay(date.year, date.month, date.day) + 0.5f;
//printf("surd(Y=%d, M=%d, D=%d, x=%d)\n", date.year, date.month, date.day, (int)days);
    // mean longitude of the Sun
    float sunLong = SunriseNormalize(280.461 * RADS + .9856474 * RADS * days);

    // mean anomaly of the Sun
    float anomaly = SunriseNormalize(357.528 * RADS + .9856003 * RADS * days);

    // Find the ecliptic longitude of the Sun
    float lambda = SunriseNormalize(sunLong + 1.915 * RADS * sin(anomaly) + .02 * RADS * sin(2.0 * anomaly));

    // Obliquity of the ecliptic
    float obliq = 23.439 * RADS - .0000004 * RADS * days;
 
    // Find the RA and DEC of the Sun
    float alpha = atan2( cos(obliq) * sin(lambda), cos(lambda) );
    float delta = asin( sin(obliq) * sin(lambda) );

//printf("sunlong=%f, anomaly=%f, lambda=%f, obliq=%f\n", sunLong, anomaly, lambda, obliq);

    // Find the Equation of Time in minutes
    float sunLong2 = sunLong - alpha;
    if (sunLong < PI) 
      sunLong2 += PI * 2;

    float equation = 1440.0 * (1.0 - sunLong2 / PI / 2.0);

    float hourAngle = SunriseHourangle(pos.lat, delta);

    // Compute sunrise / sunset times
    float dbSunrise = 12.0 - 12.0 * hourAngle / M_PI - pos.lon / 15.0 + equation / 60.0;
    float dbSunset  = 12.0 + 12.0 * hourAngle / M_PI - pos.lon / 15.0 + equation / 60.0;

    if ( dbSunrise > 24.0 ) 
      dbSunrise -= 24.0;
    if ( dbSunset > 24.0 )  
      dbSunset  -= 24.0;

    if ( dbSunrise < 0.0 ) 
      dbSunrise += 24.0;
    if ( dbSunset < 0.0 )
      dbSunset  += 24.0;

    // Conversion of angle to hours and minutes
    float yearPhase = alpha * DEGS;
    if (yearPhase < 0)
      yearPhase += 360;

    State_t state;
    state.phase = yearPhase;
    state.daylen = DEGS * hourAngle / 7.5;
    state.sunrise = dbSunrise;
    state.sunset = dbSunset;
    state.time = days - 0.5;
    
    return state;
  }

  int32_t SunriseDay(float y, float m, float d)
  {
    // get count of days relative to Year 2000
    //_ASSERT( y >= 1901 && y <= 2099 );
    int32_t luku = - 7 * (y + (m + 9) / 12) / 4 + 275 * m / 9 + d;
    // avoid overflow
    luku += y * 367;
    return luku - 730531;
  }

  float SunriseNormalize(float x)
  {
    float b = 0.5 * x / PI;
    float a = 2 * PI * (b - floor(b));
    if (a < 0) 
      a += 2 * PI;
    return a;
  }

  float SunriseHourangle(float dbLat, float dbDeclin)
  {
    const float RADS = PI/180.0;
    float dfo = RADS * (0.5 * /*SunDia*/ 0.53 + /*Air Refraction*/ 34.0 / 60.0 ); 
    if ( dbLat < 0.0 ) 
      dfo = -dfo;

    float fo = tan(dbDeclin + dfo) * tan(dbLat * RADS);

    if (fo > 0.99999) 
      fo = PI;
    else if (fo < -0.99999) 
      fo = 0.0;
    else
      fo = asin(fo) + PI / 2.0;

    return fo;
  }

  EDayNight CalculateSunrise(const State_t& sunrise, const Time_t& time)
  {
//    State_t sunrise = Sunrise(date, pos);
    //$sunrise["season"] = ["spring", "summer", "autumn", "winter"][floor($sunrise["phase"]/90)];
    //sunrise.timezone = 1;
    
    float dbCurrentTime = time.hour + time.minute / 60.0;
    //$sunrise["currentTime"] = $dbCurrentTime + sunrise.timezone;

    if ( sunrise.daylen < 0.0001 )
      return EDayNight::PolarNight;
    else if ( sunrise.daylen > 23.999 )
      return EDayNight::PolarDay;
    else
    {
      if ( sunrise.sunset > sunrise.sunrise )
      {
        if ( dbCurrentTime > sunrise.sunrise && dbCurrentTime <= sunrise.sunset)
          return EDayNight::Day;
        else
          return EDayNight::Night;
      } 
      else
      {
        if ( dbCurrentTime > sunrise.sunset && dbCurrentTime <= sunrise.sunrise)
          return EDayNight::Night;
        else
          return EDayNight::Day;
      }
    }
    return EDayNight::Unknown;
  }
};
