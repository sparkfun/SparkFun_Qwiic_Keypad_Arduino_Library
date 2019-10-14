SparkFun Qwiic Keypad Arduino Library
===========================================================

![SparkFun Qwiic Keypad - 12 Button](https://cdn.sparkfun.com//assets/parts/1/3/1/0/6/14836-Qwiic_Keypad-01.jpg)

[*SparkFun Qwiic Keypad - 12 Button (COM-15290)*](https://www.sparkfun.com/products/15290)

Keypads are very handy input devices. And there are many great libraries written to interface to keypads! But who wants to tie up 7 GPIOs, have a handful of pull up resistors, and write firmware that scans the keys taking up valuable megahertz? Let's make it easier! The Qwiic Keypad monitors all 12 buttons and allows you to read in any button presses by simply reading a register over I2C. It also implements a stack with time stamps for each key press so you don't need to constantly poll the keypad. Qwiic Keypad even has a configurable I2C address so you can have multiple keypads on the same bus! 

With this convenient Arduino Library, you don't need to worry about I2C communication protocol or register addresses. "readButton()" and "readTimeSincePressed()" take care of all the I2C stuff, and simply return the data you want. Try out the examples in this library and you'll be up and running in no time.

Qwiic Keypad is very low power and uses less than 4mA at 3.3V. There are jumpers on the board allowing the user to select between different I2C addresses as well as to remove the I2C pull up resistors if needed.

The Qwiic Keypad comes fully assembled and uses the simple Qwiic interface. No soldering, no voltage translation, no figuring out which pin is SDA or SCL, just plug and go!

The I2C address of Qwiic Keypad is software configurable which means you can hookup over 100 on a single I2C bus!

Repository Contents
-------------------

* **/examples** - Example sketches for the library (.ino). Run these from the Arduino IDE. 
* **/src** - Source files for the library (.cpp, .h).
* **keywords.txt** - Keywords from this library that will be highlighted in the Arduino IDE. 
* **library.properties** - General library properties for the Arduino package manager. 

Documentation
--------------
* **[Qwiic Keypad Hookup Guide](https://learn.sparkfun.com/tutorials/qwiic-keypad-hoookup-guide)** - Hookup guide for the Qwiic Joystick
* **[Qwiic Keypad Arduino Library](https://github.com/sparkfun/SparkFun_Qwiic_Keypad_Arduino_Library)** - Arduino library for Qwiic Keypad.
* **[Product Repository](https://github.com/sparkfun/Qwiic_Keypad)** - Main repository (including firmware and hardware files)

License Information
-------------------

This product is _**open source**_! 

Please review the LICENSE.md file for license information. 

If you have any questions or concerns on licensing, please contact technical support through the [SparkFun forum](https://forum.sparkfun.com/index.php).

Please use, reuse, and modify these files as you see fit. Please maintain attribution to SparkFun Electronics and release any derivative under the same license.

Distributed as-is; no warranty is given.

- Your friends at SparkFun.
