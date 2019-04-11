/*
  An I2C based KeyPad
  By: Nathan Seidle
  SparkFun Electronics
  Date: January 21st, 2018
  License: This code is public domain but you buy me a beer if you use this and we meet someday (Beerware license).

  KeyCode example By: Pete Lewis
  SparkFun Electronics
  Date: March 21st, 2019

  Feel like supporting our work? Buy a board from SparkFun!
  https://www.sparkfun.com/products/14641

  This example waits for the user to input the correct 4 digit keycode,
  and then responds with a nice message on serial if they get it right.
*/

#include <Wire.h>
#include "SparkFun_Qwiic_Keypad_Arduino_Library.h" //Click here to get the library: http://librarymanager/All#SparkFun_keypad
KEYPAD keypad1; //Create instance of this object

const char keyCode[] = {'1', '2', '3', '4'}; // the correct keyCode - change to your own unique set of keys if you like.
char userEntry[] = {0, 0, 0, 0}; // used to store the presses coming in from user
boolean userIsActive = false; // used to know when a user is active and therefore we want to engage timeout stuff

#define TIMEOUT 30 // 100s of milliseconds, used to reset input. 30 equates to 3 second.
byte timeOutCounter = 0; // variable this is incremented to keep track of timeouts.

byte userEntryIndex = 0; // used to keep track of where we are in the userEntry, incremented on each press, reset on timeout.

void setup(void)
{
  Serial.begin(9600);
  Serial.println("Qwiic KeyPad Example 6 - KeyCode");

  if (keypad1.begin() == false) 	// Note, using begin() like this will use default I2C address, 0x4B.
    // You can pass begin() a different address like so: keypad1.begin(Wire, 0x4A).
  {
    Serial.println("Keypad does not appear to be connected. Please check wiring. Freezing...");
    while (1);
  }
  Serial.print("Initialized. Firmware Version: ");
  Serial.println(keypad1.getVersion());
  Serial.println("\n\r\n\rPlease type in the correct 4 digit KeyCode:");
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
    //Serial.print(button);
    userEntry[userEntryIndex] = button; // store button into next spot in array, note, index is incremented later
    printEntry();
    userIsActive = true; // used to only timeout when user is active
    if (checkEntry() == true)
    {
      Serial.print("\n\r\n\rKeycode correct. Wahooooooooooo!");
      clearEntry();
      userIsActive = false; // don't display timeout stuff.
      delay(1000);
    }
    userEntryIndex++;
    if ( userEntryIndex == sizeof(keyCode)) userEntryIndex = 0; // reset
    timeOutCounter = 0; // reset with any new presses.
  }

  delay(10); //10 is good, more is better, note this effects total timeout time
  
  timeOutCounter++;
  
  if ((timeOutCounter == TIMEOUT) && (userIsActive == true)) // this means the user is actively inputing
  {
    Serial.println("\n\r\n\rTimed out... try again.");
    timeOutCounter = 0; // reset
    userEntryIndex = 0; // reset
    clearEntry();
    //printEntry();
    userIsActive = false; // so we don't continuously timeout while inactive.
  }
}

// check user entry against keyCode array.
// if they all match up, then respond with true.
boolean checkEntry()
{

  for (byte i = 0 ; i < sizeof(keyCode) ; i++)
  {
    if (userEntry[i] == keyCode[i]); // do nothing, cause we're only looking for failures
    else return false;
  }
  return true; // if we get here, all values were correct.
}

// "clear" entry with all spaces
void clearEntry()
{
  for (byte i = 0 ; i < sizeof(userEntry) ; i++)
  {
    userEntry[i] = 0; // fill with spaces
  }
}

void printEntry()
{
  Serial.println();
  Serial.print("UserEntry: ");
  for (byte i = 0 ; i < sizeof(userEntry) ; i++)
  {
    Serial.print(char(userEntry[i]));
  }
  Serial.println();
}
