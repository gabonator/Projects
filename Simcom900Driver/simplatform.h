#define GPRS_VERBOSE

#define _ASSERT(e) {if (!(e)) {Serial.print("Assertion failed " #e); while (1); }}
#define Error_print Serial.print
#define Error_printnocrlf(msg) _gprs_printnocrlf(msg)


#ifdef GPRS_VERBOSE
#define Debug_print Serial.print
#define Debug_printnocrlf Error_printnocrlf
#else
#define Debug_print(x) void()
#define Debug_printnocrlf(x) void()
#endif

#define Info_print Serial.print

/*
#include "assert.h"

#define millis() ((long)BIOS::SYS::GetTick())

void Serial_print(char c)
{
    CONSOLE::Print("%c", c);
}
void Serial_print(long l)
{
    CONSOLE::Print("%d", l);
}
void Serial_print(int n)
{
    CONSOLE::Print("%d", n);
}
void Serial_print(char* p)
{
    CONSOLE::Print("%s", p);
}
void Serial_print(const char* p)
{
    CONSOLE::Print("%s", p);
}

#define Error_print CONSOLE::Color(RGB565(ff0000)); Serial_print
#define Error_printnocrlf(msg) _gprs_printnocrlf(msg)

// Verbose output:
//#define Debug_print CONSOLE::Color(RGB565(b0b0b0)); Serial_print
//#define Debug_printnocrlf Error_printnocrlf

#define Debug_print(x) void()
#define Debug_printnocrlf(x) void()

#define Info_print CONSOLE::Color(RGB565(00ff00)); Serial_print
*/
