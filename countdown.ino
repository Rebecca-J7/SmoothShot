#include "LedControl.h"


int DIN = 12;
int CS = 10;
int CLK = 11;
int buttonPin = 7; 
bool countdownStarted = false;


LedControl lc = LedControl (DIN, CLK, CS, 1);


byte numberOne [8] =
{
  B00001000,
  B00011000,
  B00001000,
  B00001000,
  B00001000,
  B00001000,
  B00001000,
  B00011100
};


byte numberTwo [8] =
{
  B00011000,
  B00100100,
  B00000100,
  B00001000,
  B00010000,
  B00100000,
  B00100000,
  B00111100
};


byte numberThree [8] =
{
  B00111100,
  B00000100,
  B00001000,
  B00010000,
  B00001000,
  B00000100,
  B00100100,
  B00011000
};


void printOne()
{
  for (int i = 0; i < 8; ++i)
  {
    lc.setRow(0,i,numberOne[i]);
  }
}


void printTwo()
{
  for (int i = 0; i < 8; ++i)
  {
    lc.setRow(0,i,numberTwo[i]);
  }
}


void printThree()
{
  for (int i = 0; i < 8; ++i)
  {
    lc.setRow(0, i, numberThree[i]);
  }
}


void countdown()
{
  Serial.println("in countdown function");
  printThree();
  delay(1000);
  printTwo();
  delay(1000);
  printOne();
  delay(1000);
  lc.clearDisplay(0);
  delay(1000);
}


void setup() {
  lc.shutdown(0, false);
  lc.setIntensity(0, 15);
  lc.clearDisplay(0);
  pinMode(buttonPin, INPUT_PULLUP);
  Serial.begin(9600);
}


void loop() {
  if (digitalRead(buttonPin) == LOW) {
    countdownStarted = true;
    countdown();
    delay(300); // simple debounce delay
  }
}
