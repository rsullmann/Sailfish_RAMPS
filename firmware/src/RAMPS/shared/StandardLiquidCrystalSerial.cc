/* StandardLiquidCrystalSerial
 *
 * This is an implementation of communciation routines for the
 * Makerbot OEM display hardware.
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>
 */

#include "StandardLiquidCrystalSerial.hh"
#include "Configuration.hh"

#include <stdio.h>
#include <string.h>
#include <util/delay.h>
#include "TWI.hh"

//*** These functions are for using a standard LCD in 4 bit mode
StandardLiquidCrystalSerial::StandardLiquidCrystalSerial(Pin rs, Pin rw, Pin enable,Pin d0, Pin d1, Pin d2, Pin d3){
  init(rs,rw,enable,d0,d1,d2,d3);
}

void StandardLiquidCrystalSerial::init(Pin rs, Pin rw, Pin enable,Pin d0, Pin d1, Pin d2, Pin d3) {
  _rs_pin = rs;
  _rw_pin = rw;
  _enable_pin = enable;
  
  _data_pins[0] = d0;
  _data_pins[1] = d1;
  _data_pins[2] = d2;
  _data_pins[3] = d3;

#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Winline"
   _rs_pin.setDirection(true);
   _rw_pin.setDirection(true);
   _enable_pin.setDirection(true);
#pragma GCC diagnostic pop


  _displayfunction = LCD_4BITMODE | LCD_1LINE | LCD_5x8DOTS;

}

/************ low level data pushing commands **********/

// write either command or data, with automatic 4/8-bit selection
void StandardLiquidCrystalSerial::send(uint8_t value, bool mode) {
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Winline"
  //Sets the register select LCD pin low for data or high for command(mode)
  _rs_pin.setValue(mode);
  //Sets the LCD rw pin low since it always is low during a write
  _rw_pin.setValue(false);

#pragma GCC diagnostic pop
  //Write the 4 most significant bits
  write4bits((value >> 4), mode);
  //Writes the 4 least significant bits
  write4bits((value), mode);
  
}

void StandardLiquidCrystalSerial::write4bits(uint8_t value, bool dataMode) {
  for (int i = 0; i < 4; i++) {
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Winline"
    //Sets the data pins at outputs
    _data_pins[i].setDirection(true);
    //Sets the data output pin to the bit value
    _data_pins[i].setValue(((value >> i) & 0x01) != 0);
#pragma GCC diagnostic pop
  }
  //Pulse the display to read the data
  pulseEnable();
}

void StandardLiquidCrystalSerial::pulseEnable() {
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Winline"
  _enable_pin.setValue(false);
  _delay_us(1);
  _enable_pin.setValue(true);
  _delay_us(1);    // enable pulse must be >450ns
  _enable_pin.setValue(false);
  _delay_us(1);   // commands need > 37us to settle [citation needed]
#pragma GCC diagnostic pop
}
