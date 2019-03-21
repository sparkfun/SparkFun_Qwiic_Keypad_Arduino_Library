/*
  An I2C based KeyPad
  By: Nathan Seidle
  SparkFun Electronics
  Date: January 21st, 2018
  License: This code is public domain but you buy me a beer if you use this and we meet someday (Beerware license).

  Updated by: Pete Lewis
  SparkFun Electronics
  Date: March 21st, 2019

  Feel like supporting our work? Buy a board from SparkFun!
  https://www.sparkfun.com/products/14641

  This example uses a hardware iterrupt on digital pin 2 (INT0) to know when a button was pressed,
  and then prints it on Serial at Baud 9600.

  HARDWARE HOOKUP:
  Qwiic cable from controller (UNO) to Qwiic Keypad.
  "INT" pin on qwiic keypad -->> Arduino digital pin "2"

*/

#include <Wire.h>

#include "SparkFun_Qwiic_Keypad_Arduino_Library.h" //Click here to get the library: http://librarymanager/All#SparkFun_keypad

KEYPAD keypad1; //Create instance of this object

const byte interruptPin = 2; // digital pin 2 = INT0, but we will use "digitalPinToInterrupt(interruptPin)" to convert

volatile boolean buttonAvailable = false; // used to keep track if there is a button on the stack
// needs to be "volatile" because it's updated by interrupt.

void setup(void)
{
  Serial.begin(9600);
  Serial.println("Qwiic KeyPad Example 5 - InterruptRead");

  if (keypad1.begin() == false) 	// Note, using begin() like this will use default I2C address, 0x4B.
    // You can pass begin() a different address like so: keypad1.begin(Wire, 0x4A).
  {
    Serial.println("Keypad does not appear to be connected. Please check wiring. Freezing...");
    while (1);
  }
  Serial.print("Initialized. Firmware Version: ");
  Serial.println(keypad1.getVersion());

  Serial.println("Press a button and it will print here.");

  pinMode(interruptPin, INPUT); // Qwiic Keypad holds INT pin HIGH @ 3.3V, then LOW when fired.
  // Note, this means we do not want INPUT_PULLUP.

  attachInterrupt(digitalPinToInterrupt(interruptPin), intReadPrintButton, FALLING);
  // Note, INT on the Keypad will "fall" from HIGH to LOW when a new button has been pressed.
  // Also note, it will stay low while there are still button events on the stack.
  // This is useful if you want to "poll" the INT pin, rather than use a hardware interrupt.
}

void loop(void)
{
  // intReadPrintButton() is triggered via FALLING interrupt pin (digital pin 2)
  // it them updates the global variable buttonAvailable
  if (buttonAvailable)
  {
    keypad1.updateFIFO();  // necessary for keypad to pull button from stack to readable register
    Serial.print(char(keypad1.getButton()));
    buttonAvailable = false;
  }
}

void intReadPrintButton() // keep this quick; no delays, prints, I2C allowed.
{
  buttonAvailable = true;
}
