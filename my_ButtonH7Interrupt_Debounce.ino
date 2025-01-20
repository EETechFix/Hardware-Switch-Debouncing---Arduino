/*
  Evaluation MC14490P, MAX6818, and LS10 Series Switch
  Debouncers designed to eliminate the extraneous level
  changes that result from interfacing with mechanical
  switches and relays.
*/

#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

volatile byte ledState = HIGH;
volatile int direction = 1;
byte lastledState = HIGH;
int count = 0;

const byte interruptButton1 = 0;    //interrupt pin 0
const byte interruptButton2 = 1;    //interrupt pin 1
const byte interruptButton3 = 2;    //interrupt pin 2
const byte interruptButton4 = 3;    //interrupt pin 3
const byte interruptButton5 = 5;    //interrupt pin 5
const byte interruptButton6 = 6;    //interrupt pin 6
const byte interruptButton7 = 7;    //interrupt pin 7
const byte interruptButton8 = 8;    //interrupt pin 8
const byte interruptButton10 = 10;  //interrupt pin 8

Adafruit_SSD1306 display(128, 64, &Wire, -1);

void setup(){

  pinMode(LED_BUILTIN, OUTPUT);
  
  display.begin(SSD1306_SWITCHCAPVCC, 0x3D);  // Check Address; 0x3D for 128x64, 0x3C for 128x32
  display.setTextSize(4);
  display.setTextColor(WHITE);
  display.clearDisplay();
  display.drawRoundRect(0, 0, 127, 63, 8, WHITE);
  display.setCursor(20, 20);
  display.print(count);
  display.display();

  attachInterrupt(digitalPinToInterrupt(interruptButton1), toggleLEDState, FALLING);
  attachInterrupt(digitalPinToInterrupt(interruptButton2), toggleLEDState, FALLING);
  attachInterrupt(digitalPinToInterrupt(interruptButton3), toggleLEDState, FALLING);
  attachInterrupt(digitalPinToInterrupt(interruptButton4), toggleLEDState, FALLING);
  attachInterrupt(digitalPinToInterrupt(interruptButton5), toggleLEDState, FALLING);
  attachInterrupt(digitalPinToInterrupt(interruptButton6), reverseCount, FALLING);
  attachInterrupt(digitalPinToInterrupt(interruptButton7), toggleLEDState, FALLING);
  attachInterrupt(digitalPinToInterrupt(interruptButton8), toggleLEDState, FALLING);
  attachInterrupt(digitalPinToInterrupt(interruptButton10), toggleLEDState, FALLING);
}

void loop() {

  //  Green LED on
  if (ledState == HIGH) {
    digitalWrite(LED_RED, HIGH);   // Red LED off
    digitalWrite(LED_GREEN, LOW);  // Green LED on
  }

  //  Red LED on
  if (ledState == LOW) {
    digitalWrite(LED_GREEN, HIGH);  // Green off
    digitalWrite(LED_RED, LOW);     // Red LED on
  }

  if (lastledState != ledState) {
    count = count + direction;
    lastledState = ledState;
    display.clearDisplay();
    display.drawRoundRect(0, 0, 127, 63, 8, WHITE);
    display.setCursor(20, 20);
    display.print(count);
    display.display();
  }

  if (direction < 1) {
    digitalWrite(LED_BLUE, LOW);
  } else {
    digitalWrite(LED_BLUE, HIGH);
  }
}

void toggleLEDState() {
  ledState = !ledState;  // toggle LED State
}

void reverseCount() {
  direction = direction * -1;  // count increment/decrement
}
