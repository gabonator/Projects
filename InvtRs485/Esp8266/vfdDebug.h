#define _ASSERT(cond) {if (!(cond)) HandleError(__FILE__, __LINE__, #cond);}

//#define Serial_print Serial.print
template<typename T> void Serial_print(T) {};

void HandleError(char* file, int line, char* cond)
{
  debugprint("assertion failed: ");
  debugprint(file);
  debugprint(line);
  debugprint("\n");
/*
  Serial.print("\n\n============\n");
  Serial.print("Assertion failed in ");
  Serial.print(file);
  Serial.print(" [");
  Serial.print(line);
  Serial.print("]: ");
  Serial.print(cond);
  Serial.print("\n");
  while (1);
*/
}
