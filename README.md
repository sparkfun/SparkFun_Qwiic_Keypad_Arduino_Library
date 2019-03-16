SparkFun Qwiic Joystick Arduino Library
===========================================================

![SparkFun Qwiic Joystick](https://cdn.sparkfun.com/assets/parts/1/3/5/5/8/15168-SparkFun_Qwiic_Joystick-01.jpg)

[*SparkFun Qwiic Joystick (DEV-15168)*](https://www.sparkfun.com/products/15168)

Sometimes you need a joystick in your project. The Qwiic Joystick is a great solution with an analog joystick and momentary button. The Qwiic Joystick was designed to get rid of the large mass of wires that are needed to implement a joystick on a breadboard. The ATtiny85 on the Qwiic Joystick takes care reading the joystick position and if the button is pressed, while making that data readable over an easy-to-use I<sup>2</sup>C interface.

The joystick has a built in button so the user can select an GUI menu or element by pressing on the joystick. The current position of the joystick and state of the button are readable through the I2C registers. In the firmware, there is also a seperate register to check for button presses inbetween reads of the button state, which is cleared after each read (also with the read of the button state).

The I2C address of Qwiic Joystick is software configurable which means you can hookup over 100 on a single I2C bus!

Repository Contents
-------------------

* **/examples** - Example sketches for the library (.ino). Run these from the Arduino IDE. 
* **/src** - Source files for the library (.cpp, .h).
* **keywords.txt** - Keywords from this library that will be highlighted in the Arduino IDE. 
* **library.properties** - General library properties for the Arduino package manager. 

Documentation
--------------
* **[Qwiic Joystick Hookup Guide](https://learn.sparkfun.com/tutorials/qwiic-joystick-hoookup-guide)** - Hookup guide for the Qwiic Joystick
* **[Installing an Arduino Library Guide](https://learn.sparkfun.com/tutorials/installing-an-arduino-library)** - Basic information on how to install an Arduino library.
* **[Product Repository](https://github.com/sparkfun/Qwiic_Joystick)** - Main repository (including hardware files)

License Information
-------------------

This product is _**open source**_! 

Please review the LICENSE.md file for license information. 

If you have any questions or concerns on licensing, please contact techsupport@sparkfun.com.

Please use, reuse, and modify these files as you see fit. Please maintain attribution to SparkFun Electronics and release any derivative under the same license.

Distributed as-is; no warranty is given.

- Your friends at SparkFun.
