#include <EEPROM.h>

unsigned int addr = 0;
unsigned int val =  0;

void setup()
{
  // initialize serial and wait for port to open:
  Serial.begin(115200);
  while (!Serial) {
    // wait for serial port to connect. Needed for Leonardo only
  }
}

void loop()
{  

   //clear all eeprom
  for(int i=0;i<512;i++)
  {
    EEPROM.write(i, 0);          //clear
  }

  // write the value to the appropriate byte of the EEPROM.
  /*
  for(int i=0;i<512;i++)
  {
    addr = i;
    val  = i;
    EEPROM.write(addr, val);    
  }
 */
  val = EEPROM.read(addr);   //read 1 byte
  // there are 512 bytes in the EEPROM
  Serial.print(addr);
  Serial.print("\t");
  Serial.print(val, DEC);
  Serial.println();
  
  addr = addr + 1;
  if (addr == 512)
    addr = 0;
  
  delay(100);
}
