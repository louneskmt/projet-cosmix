#include <EEPROM.h>

int addr = 0;
char serialnumber[] = "1-02";


void setup()
{
  // need to divide by 4 because analog inputs range from
  // 0 to 1023 and each byte of the EEPROM can only hold a
  // value from 0 to 255.
  while (serialnumber[addr])
    {
     EEPROM.write(addr, serialnumber[addr]);
     addr = addr + 1;   
    }
  EEPROM.write(addr, 0);
}

void loop()
{
}
