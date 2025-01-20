/*
  Evaluation MC14490P, MAX6818, and LS10 Series Switch
  Debouncers designed to eliminate the extraneous level
  changes that result from interfacing with mechanical
  switches.
*/

#include "Arduino_LED_Matrix.h"   // Include the LED_Matrix library
#include "frames.h"               // Include a header file containing frame data

ArduinoLEDMatrix matrix;          // Create an instance of the ArduinoLEDMatrix class

const byte interruptButton1 = 2; //interrupt pin 2
const byte interruptButton2 = 3; //interrupt pin 3

volatile byte frameState = HIGH;

void setup() {
  Serial.begin(115200);  // Initialize serial communication 
  if (! Serial) {
    delay (2000); // port not ready, delay for native USB boards
  }
  matrix.begin();        // Initialize the LED matrix

  attachInterrupt(digitalPinToInterrupt(interruptButton1), toggle, FALLING);
  attachInterrupt(digitalPinToInterrupt(interruptButton2), toggle, FALLING);

}

void loop() {

  // Load and display the "heart" frame on the LED matrix
  if (frameState == LOW) {
    matrix.loadFrame(low);
  }

  // Load and display the "fullOn" frame on the LED matrix
  if (frameState == HIGH) {
    matrix.loadFrame(high);
  }
}
void toggle() {
  frameState = !frameState;
}
