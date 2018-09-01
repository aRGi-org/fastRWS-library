


// import fastRWS library
#include <fastRWS.h>

//Arduuino UNO pin numbers
// use these constants to identify pins
#define DIGITAL_PIN_0  0
#define DIGITAL_PIN_1  1
#define DIGITAL_PIN_2  2
#define DIGITAL_PIN_3  3
#define DIGITAL_PIN_4  4
#define DIGITAL_PIN_5  5
#define DIGITAL_PIN_6  6
#define DIGITAL_PIN_7  7

#define DIGITAL_PIN_8  8
#define DIGITAL_PIN_9  9
#define DIGITAL_PIN_10  10
#define DIGITAL_PIN_11  11
#define DIGITAL_PIN_12  12
#define DIGITAL_PIN_13  13


//Code Initialization
void setup() {
  // set digital pin 4 mode to output
  // you may also connect a led to the this pin
  pModeDigital(DIGITAL_PIN_4, OUTPUT);


  // init serial monitor (i love high speed:))
  Serial.begin(115200);
  Serial.print("Initializing...\n");
}


void loop() {

  // write to pin 4 negation of the current value of pin 4
  pWriteDigital(DIGITAL_PIN_4,(!(pReadDigital(DIGITAL_PIN_4))));

  // you may also print the current value of the pin
  Serial.print("PIN value is ");
  Serial.print(pReadDigital(DIGITAL_PIN_4));
  Serial.print("\n");
 
  // wait 1 second
  delay(1000);
} // end loop