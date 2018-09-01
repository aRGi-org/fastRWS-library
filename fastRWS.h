// 
// FILE: fastRWS.h
// VERSION: 0.0.1
// PURPOSE: fast Read Write and Set GPIO digital pins for Arduino
// LICENSE: GPL v3 (http://www.gnu.org/licenses/gpl.html)
//
//     URL: none 
//
// HISTORY:
// aRGi Roberto Giancane - Original version
// see fastRWS.cpp
// 

#include <Arduino.h>

volatile uint8_t pReadDigital(int pin);
volatile uint8_t pWriteDigital(int pin, int val);
volatile uint8_t pModeDigital(int pin, int direction);

//
// END OF FILE