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

// read digital pin specyfied by int value pin
volatile uint8_t pReadDigital(int pin) {

	volatile uint8_t *port = ((pin & 8) == 8) ? &PINB : &PIND;
	volatile uint8_t bitNo = 1 << (((pin & 8) == 8) ? pin - 8 : pin);

	return (*port & bitNo) == bitNo ? 1 : 0;
}

// write digital pin specyfied by int value pin, int val is the value, 1 or 0
volatile uint8_t pWriteDigital(int pin, int val) {
	
  volatile uint8_t *port = ((pin & 8) == 8) ? &PORTB : &PORTD;
  volatile uint8_t bitNo = 1 << (((pin & 8) == 8) ? pin - 8 : pin);
  int bitVal = (val == 1) ? *port | (1 << (((pin & 8) == 8) ? pin - 8 : pin)) : *port & (~(1 << (((pin & 8) == 8) ? pin - 8 : pin)));

  *port = (uint8_t) bitVal;

  return (*port & bitNo) == bitNo ? 1 : 0;
}

// set pin mode of pin spicified by int value pin, int value direction INPUT or OUTPUT
volatile uint8_t pModeDigital(int pin, int direction) {
	
  volatile uint8_t *port = ((pin & 8) == 8) ? &DDRB : &DDRD;
  volatile uint8_t bitNo = 1 << (((pin & 8) == 8) ? pin - 8 : pin);
  int bitVal = (direction == 1) ? *port | (1 << (((pin & 8) == 8) ? pin - 8 : pin)) : *port & (~(1 << (((pin & 8) == 8) ? pin - 8 : pin)));

  *port = (uint8_t) bitVal;

  return (*port & bitNo) == bitNo ? 1 : 0;
}

//
// END OF FILE