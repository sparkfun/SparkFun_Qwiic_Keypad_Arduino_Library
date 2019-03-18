/*
  An I2C based KeyPad
  By: Nathan Seidle
  SparkFun Electronics
  Date: January 21st, 2018
  License: This code is public domain but you buy me a beer if you use this and we meet someday (Beerware license).

  Updated by: Pete Lewis
  SparkFun Electronics
  Date: March 16th, 2019

  Feel like supporting our work? Buy a board from SparkFun!
  https://www.sparkfun.com/products/14641

  This example prints which button was pressed. Press * for space and # for new line.

  Qwiic KeyPad records any button presses to a stack. It can remember up to 15 buttone presses.
  The master I2C device (for example, an Uno) can ask for the oldest button pressed.
  If the master continues to read in button presses, it will receive the entire stack (from oldest to newest).
  This is handy if you need to go and do something else with your code, you can then come back to the
  keypad and pull in the last 15 button presses.
*/

#include <Wire.h>
#include "SparkFun_Qwiic_Keypad_Arduino_Library.h" //Click here to get the library: http://librarymanager/All#SparkFun_keypad
KEYPAD keypad1; //Create instance of this object

void setup(void)
{
  Serial.begin(9600);
  Serial.println("Qwiic KeyPad Example");

  if (keypad1.begin() == false) 	// Note, using begin() like this will use default I2C address, 0x4B. 
									// You can pass begin() a different address like so: keypad1.begin(Wire, 0x4A).
  {
    Serial.println("Keypad does not appear to be connected. Please check wiring. Freezing...");
    while (1);
  }
  Serial.print("Initialized. Firmware Version: ");
  Serial.println(keypad1.getVersion());
  Serial.println("Press a button: * to do a space. # to go to next line.");
}

void loop(void)
{
  keypad1.updateFIFO();  // necessary for keypad to pull button from stack to readable register
  char button = keypad1.getButton();

  if (button == -1)
  {
    Serial.println("No keypad detected");
    delay(1000);
  }
  else if (button != 0)
  {
    if (button == '#') Serial.println();
    else if (button == '*') Serial.print(" ");
    else Serial.print(button);
  }

  //Do something else. Don't call your Keypad a ton otherwise you'll tie up the I2C bus
  delay(25); //25 is good, more is better
}