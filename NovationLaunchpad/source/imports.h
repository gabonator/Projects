extern "C" {
  extern uint32_t LED_BUFFER[];
  extern uint8_t MODE;
  extern int32_t TICKSMS;
  extern int32_t INTROPHASE;
  extern uint8_t fontData[];
  extern uint16_t fontOffsets[];
  extern uint8_t WATERDEMO;

  void old_loop();
  void new_loop();
  void old_onPress(int, int);
  void new_onPress(int, int);
  void old_onRelease(int);
  void new_onRelease(int);
  void old_updateScreen();
  void new_updateScreen();
  int old_usbStatus();
  int new_usbStatus();
  void old_startup();
  void new_startup();
  void old_introGradient(int, uint32_t);
  void new_introGradient(int, uint32_t);

  extern uint32_t _sidata;
  extern uint32_t _sdata;
  extern uint32_t _edata;
  extern uint32_t _sbss;
  extern uint32_t _ebss;
  extern uint32_t _sinit;
  extern uint32_t _einit;
}
