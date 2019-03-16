/*
  This is a library written for the SparkFun Qwiic Keypad
  SparkFun sells these at its website: www.sparkfun.com
  Do you like this library? Help support SparkFun. Buy a board!
  https://www.sparkfun.com/products/15168

  Written by Pete Lewis @ SparkFun Electronics, 3/12/2019
  Much of the code originally came from SparkX version,
  Located here: https://github.com/sparkfunX/Qwiic_Keypad

  The Qwiic Keypad is a I2C controlled 12 button keypad

  https://github.com/sparkfun/SparkFun_Qwiic_Keypad_Arduino_Library

  Development environment specifics:
  Arduino IDE 1.8.8

  This program is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
  GNU General Public License for more details.

  You should have received a copy of the GNU General Public License
  along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#ifndef _SPARKFUN_QWIIC_KEYPAD_ARDUINO_LIBRARY_H
#define _SPARKFUN_QWIIC_KEYPAD_ARDUINO_LIBRARY_H
#include "Arduino.h"
#include "Wire.h"

#define QWIIC_KEYPAD_ADDR 0x4B //7-bit unshifted default I2C Address

//Map to the various registers on the Keypad
enum encoderRegisters {
  KEYPAD_ID = 0x00,
  KEYPAD_VERSION1, // 0x01
  KEYPAD_VERSION2, // 0x02
  KEYPAD_BUTTON, // 0x04
  KEYPAD_TIME_MSB, // 0x05
  KEYPAD_TIME_LSB, // 0x06
  KEYPAD_UPDATE_FIFO, // 0x07
  KEYPAD_CHANGE_ADDRESS, // 0x08
};

class KEYPAD {
  public:
    KEYPAD();

    boolean begin(TwoWire &wirePort = Wire, uint8_t deviceAddress = QWIIC_KEYPAD_ADDR);
    boolean isConnected(); //Checks if sensor ack's the I2C request
	String getVersion(); //Returns a two byte Major/Minor version number	
	
    uint8_t getButton(); //Returns the button at the top of the stack (aka the oldest button)
	uint16_t getTimeSincePressed(); //Returns the 16 bit number of time since button pressed
	void updateFIFO(); 	// "commands" keypad to plug in the next button into the registerMap
						// note, this actually sets the bit0 on the updateFIFO register
	
	void setI2CAddress(uint8_t newAddress); //Change the I2C address to newAddress (Prints new address over serial)
	
  private:
    TwoWire *_i2cPort;
	uint8_t _deviceAddress;
    boolean writeRegister(uint8_t addr, uint8_t val);
    uint8_t readRegister(uint8_t addr);

};

#endif