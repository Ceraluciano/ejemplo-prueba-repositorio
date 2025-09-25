#include <Arduino.h>
#include <TEA5767Radio.h>

TEA5767Radio::TEA5767Radio(int address)
{
  _address = address;
}

TEA5767Radio::TEA5767Radio()
{
  _address = 0x60;
}


void TEA5767Radio::setFrequency(float frequency)
{
  	unsigned int frequencyB = 4 * (frequency * 1000000 + 225000) / 32768; 
	byte frequencyH = frequencyB >> 8;
	byte frequencyL = frequencyB & 0XFF;
	Wire.beginTransmission(_address); 
	Wire.write(frequencyH);
	Wire.write(frequencyL);
	Wire.write(0xB0);
	Wire.write(0x10);
	Wire.write(0x00);
	Wire.endTransmission();
	delay(100);  
}
