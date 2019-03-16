/*
  An I2C based KeyPad
  By: Nathan Seidle
  SparkFun Electronics
  Date: January 21st, 2018
  License: This code is public domain but you buy me a beer if you use this and we meet someday (Beerware license).

  Feel like supporting our work? Buy a board from SparkFun!
  https://www.sparkfun.com/products/14641

  This example prints which button was pressed. Press * for space and # for new line.

  Qwiic KeyPad records any button presses to a stack. If quered by the master KeyPad will
  respond with the oldest button pressed along with the time since it was pressed.
*/

#include <Wire.h>
#include "SparkFun_Qwiic_Keypad_Arduino_Library.h" //Click here to get the library: http://librarymanager/All#SparkFun_keypad
KEYPAD keypad1; //Create instance of this object

void setup(void)
{
  Serial.begin(9600);
  Serial.println("Qwiic KeyPad Example");

  if (keypad1.begin() == false)
  {
    Serial.println("Joystick does not appear to be connected. Please check wiring. Freezing...");
    while (1);
  }

  Serial.println("Press a button: * to do a space. # to go to next line.");
  keypad1.updateFIFO();
  Serial.print(" Version: ");
  Serial.println(keypad1.getVersion());
}

void loop(void)
{
  delay(5000);
  char button = keypad1.getButton();
  Serial.print(" Button: ");
  Serial.println(button);
  delay(5000);
  Serial.print("Commanding update fifo");
  keypad1.updateFIFO();
  
  //  char button = readKeyPad();
  //
  //  if (button == -1)
  //  {
  //    Serial.println("No keypad detected");
  //    delay(1000);
  //  }
  //  else if (button != 0)
  //  {
  //    if (button == '#') Serial.println();
  //    else if (button == '*') Serial.print(" ");
  //    else Serial.print(button);
  //  }

  //Do something else. Don't call readKeyPad a ton otherwise you'll tie up the I2C bus
  delay(25); //25 is good, more is better
}

////Get the latest button
//char readKeyPad()
//{
//  Wire.requestFrom((uint8_t)keypadAddress, (uint8_t)1);
//  return (Wire.read());
//}