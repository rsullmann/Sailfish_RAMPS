/*
 * Copyright 2010 by Adam Mayer	 <adam@makerbot.com>
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

#ifndef BOARDS_MBV40_CONFIGURATION_HH_
#define BOARDS_MBV40_CONFIGURATION_HH_

#include "Model.hh"

// Bot type used in stream version command
#define BOT_TYPE 0xD314

// --- Axis configuration ---
// Define the number of stepper axes supported by the board.  The axes are
// denoted by X, Y, Z, A and B.
#define STEPPER_COUNT   5
#define MAX_STEPPERS    5
#define EXTRUDERS       2

// microstepping is 1 / (1 << MICROSTEPPING)
//  0 for 1/1
//  1 for 1/2
//  2 for 1/4
//  3 for 1/8
//  4 for 1/16
//  5 for 1/32
//  etc.
#define MICROSTEPPING   4

#ifndef SIMULATOR

// This file details the pin assignments and features of the Makerbot Extended Motherboard 4.0

#include "AvrPort.hh"

// Enable the P-Stop (pause stop) support
#define PSTOP_SUPPORT

// --- Power Supply Unit configuration ---
// Define as 1 if a PSU is present; 0 if not.
#define HAS_PSU         0

///// ******* SD CARD CONFIGURATION  ***************/////
// NOTE: If SD support is enabled, it is implicitly assumed that the
// following pins are connected:
//  AVR    |   SD header
//---------|--------------
//  MISO   |   DATA_OUT
//  MOSI   |   DATA_IN
//  SCK    |   CLK

// Define as 1 if an SD card slot is present; 0 if not.
#define HAS_SD          0
// The pin that connects to the write protect line on the SD header.
#define SD_WRITE_PIN    Pin(PortD,0) //Digital Pin # 21
// The pin that connects to the card detect line on the SD header.
#define SD_DETECT_PIN   Pin(PortL,0) //Digital Pin #49
// The pin that connects to the chip select line on the SD header.
#define SD_SELECT_PIN   Pin(PortB,0) //Digital Pin #53

///// ******* HOST AND SLAVE UART CONFIGURATION  ***************/////
// The host UART is presumed to always be present on the RX/TX lines.
// The slave UART is presumed to be an RS485 connection through a sn75176 chip.
// Define as 1 if the slave UART is present; 0 if not.
#define HAS_SLAVE_UART 0
// The pin that connects to the driver enable line on the RS485 chip.
//#define TX_ENABLE_PIN           Pin(PortD,3) //Digital Pin #18
// The pin that connects to the active-low recieve enable line on the RS485 chip.
//#define RX_ENABLE_PIN           Pin(PortD,2) //Digital Pin #19

///// ******* PIEZO BUZZER  ***************/////
// Define as 1 if the piezo buzzer is present, 0 if not.
#define HAS_BUZZER 0
// The pin that drives the buzzer
#define BUZZER_PIN Pin(PortG,5)  //Digital Pin #4

///// *******Stepper Axis Definitions and Ports  ***************/////
// This indicates the default interpretation of the endstop values.
// If your endstops are based on the H21LOB, they are inverted;
// if they are based on the H21LOI, they are not.
#define DEFAULT_INVERTED_ENDSTOPS 1
//STEPPER_STEP=active rising edge
//STEPPER_DIR=forward on high
//STEPPER_ENABLE=active low
//STEPPER_MIN=active high
//STEPPER_MAX=active high

#define X_STEPPER_STEP          STEPPER_PORT(F,0)	//..Digital Pin #54
#define X_STEPPER_DIR           STEPPER_PORT(F,1)	//..Digital Pin #55
#define X_STEPPER_ENABLE        STEPPER_PORT(D,7)	//..Digital Pin #38
#define X_STEPPER_MIN           STEPPER_PORT(E,5)	//..Digital Pin #3
#define X_STEPPER_MAX           STEPPER_PORT(E,4)	//..Digital Pin #2

#define X_HOMING_TIMEOUT  60  //Defines the Timeout used when homing the X axis
#define X_HOME_MAX            //X Axis Endstop is at the maximum point

// P-Stop is X_STEPPER_MAX
#define PSTOP_PORT  Pin(PortE,4) //..Digital Pin #3
#ifdef PSTOP_VECT
#undef PSTOP_VECT
#endif

#define Y_STEPPER_STEP          STEPPER_PORT(F,6)	//..Digital Pin #60
#define Y_STEPPER_DIR           STEPPER_PORT(F,7)	//..Digital Pin #61
#define Y_STEPPER_ENABLE        STEPPER_PORT(F,2)	//..Digital Pin #56
#define Y_STEPPER_MIN           STEPPER_PORT(J,1)	//..Digital Pin #14
#define Y_STEPPER_MAX           STEPPER_PORT(J,0)	//..Digital Pin #15

#define Y_HOMING_TIMEOUT  60  //Defines the Timeout used when homing the Y Axis
#define Y_HOME_MIN            //Y Axis Endstop is at the minimum

#define Z_STEPPER_STEP          STEPPER_PORT(L,3)	//..Digital Pin #46
#define Z_STEPPER_DIR           STEPPER_PORT(L,1)	//..Digital Pin #48
#define Z_STEPPER_ENABLE        STEPPER_PORT(K,0)	//..Digital Pin #62
#define Z_STEPPER_MIN           STEPPER_PORT(D,3)	//..Digital Pin #18
#define Z_STEPPER_MAX           STEPPER_PORT(D,2)	//..Digital Pin #19

#define Z_HOMING_TIMEOUT  60  //Defines the Timeout used when homing the Z axis
#define Z_HOME_MAX           //Defined since Z Max is where the end stop is at

//Extruder #1 or other
#define A_STEPPER_STEP          STEPPER_PORT(A,4)	//..Digital Pin #26
#define A_STEPPER_DIR           STEPPER_PORT(A,6)	//..Digital Pin #28
#define A_STEPPER_ENABLE        STEPPER_PORT(A,2)	//..Digital Pin #24

//Extruder #2 or other
#define B_STEPPER_STEP          STEPPER_PORT(C,1)	//..Digital Pin #36
#define B_STEPPER_DIR           STEPPER_PORT(C,3)	//..Digital Pin #34
#define B_STEPPER_ENABLE        STEPPER_PORT(C,7)	//..Digital Pin #30

// --- Debugging configuration ---
// The pin which controls the debug LED (active high)
#define DEBUG_PIN       Pin(PortB,7) //This matches the LED on the Ramps1.3 Board
// Additional Debug Pins
#define DEBUG_PIN1	Pin(PortH,1) //..Digital Pin #16
#define DEBUG_PIN2	Pin(PortH,0) //..Digital Pin #17
#define DEBUG_PIN3	Pin(PortC,0) //..Digital Pin #39
#define DEBUG_PIN4  	Pin(PortG,0) //..Digital Pin #41
#define DEBUG_PIN5  	Pin(PortL,6) //..Digital Pin #43
#define DEBUG_PIN6  	Pin(PortL,4) //..Digital Pin #45
#define DEBUG_PIN7  	Pin(PortL,2) //..Digital Pin #47
#define DEBUG_PIN8  	Pin(PortC,5) //..Digital Pin #32

// By default, debugging packets should be honored; this is made
// configurable if we're short on cycles or EEPROM.
// Define as 1 if debugging packets are honored; 0 if not.
#define HONOR_DEBUG_PACKETS 0

///// *******INTERFACE CONFIGURATION  ***************/////
//Interface includes a keypad and LCD display
#define HAS_INTERFACE_BOARD     1

///// *******LCD SETTINGS  ***************/////
//4 Bit Mode Connected LCD Panel
#define LCD_RS_PIN		Pin(PortK,1)//..Digital Pin #63
#define LCD_RW_PIN		Pin(PortL,7)//..Digital Pin #42
#define LCD_ENABLE_PIN          Pin(PortK,3)//..Digital Pin #65
#define LCD_D0_PIN		Pin(PortF,5)//..Digital Pin #59
#define LCD_D1_PIN		Pin(PortK,2)//..Digital Pin #64
#define LCD_D2_PIN		Pin(PortL,5)//..Digital Pin #44
#define LCD_D3_PIN		Pin(PortK,4)//..Digital Pin #66

/// Character LCD screen geometry
#define LCD_SCREEN_WIDTH        20
#define LCD_SCREEN_HEIGHT       4

/// This is the pin mapping for the 16 button interface keypad. 
/// Because of the relatively high cost of using the pins in a direct manner, we will instead read the
/// buttons directly by scanning their ports. If any of these definitions are
/// modified, the standardbuttonarray.cc must be updated in the respective board folder
#define INTERFACE_ROW1		Pin(PortA,1) //..Digital Pin #23
#define INTERFACE_ROW2		Pin(PortA,3) //..Digital Pin #25
#define INTERFACE_ROW3		Pin(PortA,5) //..Digital Pin #27
#define INTERFACE_ROW4		Pin(PortA,7) //..Digital Pin #29
#define INTERFACE_COL1		Pin(PortC,0) //..Digital Pin #37
#define INTERFACE_COL2		Pin(PortC,2) //..Digital Pin #35
#define INTERFACE_COL3		Pin(PortC,4) //..Digital Pin #33
#define INTERFACE_COL4		Pin(PortC,6) //..Digital Pin #31

///// **** HBP and Extruder  ***************/////

///// **** Thermistors  ***************/////
/// Should be defined if there are any thermistors on the board
#define HAS_THERMISTOR_TABLES
#define EXTRUDER_THERMISTOR_PIN          13 //PortK,5..Analog Pin 13
#define EXTRUDER2_THERMISTOR_PIN         15 //PortK,7..Analog Pin 15
#define PLATFORM_PIN            	 14 //PortK,6...Analog Pin 14

///// **** Thermocouples  ***************/////
#define HAS_THERMOCOUPLE        0
#define DEFAULT_THERMOCOUPLE_VAL	1024
//#define THERMOCOUPLE_CS1        Pin(PortE,3)
//#define THERMOCOUPLE_CS2        Pin(PortE,4)
//#define THERMOCOUPLE_SCK        Pin(PortE,2)
//#define THERMOCOUPLE_SO         Pin(PortE,5)

/// POWER Pins for extruders, fans and heated build platform
#define EX1_PWR	                Pin(PortB,4) //..Digital Pin #10
#define EX2_PWR	                Pin(PortH,4) //..Digital Pin #7
#define EX1_FAN                 Pin(PortH,6) //..Digital Pin #9
#define HBP_HEAT                Pin(PortH,5) //..Digital Pin #8 
#define EX2_FAN                 Pin(PortH,3) //..Digital Pin #6
#define EX_FAN                  Pin(PortE,0) //..Digital Pin #0
#define EXTRA_FET               Pin(PortE,3) //..Digital Pin #5

//What is this exactly controlling??Part Cooling fan?
//#define ACTIVE_COOLING_FAN

// sample intervals for heaters
#define SAMPLE_INTERVAL_MICROS_THERMISTOR (250L * 1000L)
#define SAMPLE_INTERVAL_MICROS_THERMOCOUPLE (500L * 1000L)

///// **** Safety Cutoff Circuit  ***************/////
#define CUTOFF_PRESENT   0
// safety cutoff circuit 
#define CUTOFF_RESET			Pin(PortF,4)//..Digital Pin #58
#define CUTOFF_TEST			Pin(PortD,1)//..Digital Pin #20
#define CUTOFF_SR_CHECK			Pin(PortF,3)//..Digital Pin #57

// bot shuts down printers after a defined timeout
#define USER_INPUT_TIMEOUT		1800000000 // 30 minutes

//If defined, erase the eeprom area on every boot, useful for diagnostics
//#define ERASE_EEPROM_ON_EVERY_BOOT

//If defined, enable an additional Utilities menu that allows erasing, saving and loading
//of eeprom data
#define EEPROM_MENU_ENABLE

//If defined, the planner is constrained to a pipeline size of 1,
//this means that acceleration still happens, but only on a per block basis,
//there's no speeding up between blocks.
//#define PLANNER_OFF

//If defined sets the debug header (DEBUG_PIN1/2/3/4/5/6/7/8) to the given value
//#define DEBUG_VALUE(x)	setDebugValue(x)

//If defined provides 2 debugging variables for on screen display during build
//Variables are floats:  debug_onscreen1, debug_onscreen2 and can be found in Steppers.hh
//#define DEBUG_ONSCREEN

//If defined, the stack is painted with a value and the free sram reported in
//in the Version menu.  This enables debugging to see if the SRAM was ever exhausted
//which would lead to stack corruption.
#define STACK_PAINT

//Definitions for the timer / counter  to use for the stepper interrupt
//Change this to a different 16 bit interrupt if you need to
#define STEPPER_OCRnA			OCR3A
#define STEPPER_TIMSKn			TIMSK3
#define STEPPER_OCIEnA			OCIE3A
#define STEPPER_TCCRnA			TCCR3A
#define STEPPER_TCCRnB			TCCR3B
#define STEPPER_TCCRnC			TCCR3C
#define STEPPER_TCNTn			TCNT3
#define STEPPER_TIMERn_COMPA_vect	TIMER3_COMPA_vect

//Oversample the dda to provide less jitter.
//To switch off oversampling, comment out
//2 is the number of bits, as in a bit shift.  So << 2 = multiply by 4
//= 4 times oversampling
//Obviously because of this oversampling is always a power of 2.
//Don't make it too large, as it will kill performance and can overflow int32_t
//#define OVERSAMPLED_DDA 2

#endif // !SIMULATOR

#define JKN_ADVANCE

//Minimum time in seconds that a movement needs to take if the planning pipeline command buffer is
//emptied. Increase this number if you see blobs while printing high speed & high detail. It will
//slowdown on the detailed stuff.
#define ACCELERATION_MIN_SEGMENT_TIME 0.0200

//Minimum planner junction speed (mm/sec). Sets the default minimum speed the planner plans for at 
//the end of the buffer and all stops. This should not be much greater than zero and should only be 
//changed if unwanted behavior is observed on a user's machine when running at very slow speeds. 
//2mm/sec is the recommended value.
#define ACCELERATION_MIN_PLANNER_SPEED 2

//Slowdown limit specifies what to do when the pipeline command buffer starts to empty.
//The pipeline command buffer is 16 commands in length, and Slowdown Limit can be set 
//between 0 - 8 (half the buffer size).
//
//When Commands Left <= Slowdown Limit, the feed rate is progressively slowed down as the buffer 
//becomes more empty.
//
//By slowing down the feed rate, you reduce the possibility of running out of commands, and creating 
//a blob due to the stopped movement.
//
//Possible values are:
//
//0 - Disabled - Never Slowdown
//1 - DON'T USE
//2 - DON'T USE
//3,4,5,6,7,8 - The higher the number, the earlier the start of the slowdown
#define ACCELERATION_SLOWDOWN_LIMIT 4

//ACCELERATION_EXTRUDER_WHEN_NEGATIVE specifies the direction of extruder.
//If negative steps cause an extruder to extrude material, then set this to true.
//If positive steps cause an extruder to extrude material, then set this to false.
//Note: Although a Replicator can have 2 extruders rotating in opposite directions,
//both extruders require negative steps to extrude material.
//This setting effects "Advance" and "Extruder Deprime".
#define ACCELERATION_EXTRUDE_WHEN_NEGATIVE_A true
#define ACCELERATION_EXTRUDE_WHEN_NEGATIVE_B true

// If defined, overlapping stepper interrupts don't cause clunking
// The ideal solution it to adjust calc_timer, but this is just a safeguard
#define ANTI_CLUNK_PROTECTION

//If defined, speed is drastically reducing to crawling
//Very useful for watching acceleration and locating any bugs visually
//Only slows down when acceleration is also set on.
//#define DEBUG_SLOW_MOTION

//If defined, the toolhead and hbp are not heated, and there's
//no waiting.
//This is useful to test movement without extruding any plastic.
//HIGHLY ADVISABLE TO HAVE NO FILAMENT LOADED WHEN YOU DO THIS
//#define DEBUG_NO_HEAT_NO_WAIT

//If defined (and STACK_PAINT is defined), SRAM is monitored occasionally for
//corruption, signalling and 6 repeat error tone on the buzzer if it occurs.
//#define DEBUG_SRAM_MONITOR

//When a build is cancelled or paused, we clear the nozzle
//from the build volume.  This denotes the X/Y/Z position we should
//move to.  max/min_axis_steps_limit can be used for the limits of an axis.
//If you're moving to a position that's an end stop, it's advisable to
//clear the end stop by a few steps as you don't want the endstop to
//be hit due to positioning accuracy and the possibility of an endstop triggering
//a few steps around where it should be.

//If BUILD_CLEAR_a isn't defined, then no motion along axis "a"
//is executed whilst clearing the build platform.

#define BUILD_CLEAR_MARGIN 5.0 // 5.0 mm

#ifndef X_HOME_MIN

// ***** WARNING ***** Math for _X assumes X home offset is positive....
#define BUILD_CLEAR_X ( (int32_t)eeprom::getEeprom32(eeprom_offsets::AXIS_HOME_POSITIONS_STEPS + X_AXIS * sizeof(uint32_t), stepperAxis[X_AXIS].max_axis_steps_limit) - (int32_t)(BUILD_CLEAR_MARGIN * stepperAxisStepsPerMM(X_AXIS)) )

#else

// ***** WARNING ***** Math for _X assumes X home offset is negative....
#define BUILD_CLEAR_X ( (int32_t)eeprom::getEeprom32(eeprom_offsets::AXIS_HOME_POSITIONS_STEPS + X_AXIS * sizeof(uint32_t), stepperAxis[X_AXIS].max_axis_steps_limit) + (int32_t)(BUILD_CLEAR_MARGIN * stepperAxisStepsPerMM(X_AXIS)) )

#endif

#ifndef Y_HOME_MIN

// ***** WARNING ***** Math for __Y assumes Y home offsets is positive....
#define BUILD_CLEAR_Y ( (int32_t)eeprom::getEeprom32(eeprom_offsets::AXIS_HOME_POSITIONS_STEPS + Y_AXIS * sizeof(uint32_t), stepperAxis[Y_AXIS].max_axis_steps_limit) - (int32_t)(BUILD_CLEAR_MARGIN * stepperAxisStepsPerMM(Y_AXIS)) )

#else

// ***** WARNING ***** Math for __Y assumes Y home offsets is negative....
#define BUILD_CLEAR_Y ( (int32_t)eeprom::getEeprom32(eeprom_offsets::AXIS_HOME_POSITIONS_STEPS + Y_AXIS * sizeof(uint32_t), stepperAxis[Y_AXIS].max_axis_steps_limit) + (int32_t)(BUILD_CLEAR_MARGIN * stepperAxisStepsPerMM(Y_AXIS)) )

#endif

#ifndef Z_HOME_MAX

// ****** WARNING ***** Overall math for _Z, including [Z_AXIS].max_axis_steps_limit from StepperAxis.cc,
// assumes Z home offset/position is close to zero.
#define BUILD_CLEAR_Z (stepperAxis[Z_AXIS].max_axis_steps_limit)

#else

// We home to Z max and so we want to clear down to Z max - 5 mm.  This works UNLESS the build is so tall
// that when the pause occurs we're actually closer than 5 mm to the Z end stop.  In that case we actually
// drive the print back into the nozzle!!!!
#define BUILD_CLEAR_Z  ( (int32_t)eeprom::getEeprom32(eeprom_offsets::AXIS_HOME_POSITIONS_STEPS + Z_AXIS * sizeof(uint32_t), stepperAxis[Z_AXIS].max_axis_steps_limit) - (int32_t)(BUILD_CLEAR_MARGIN * stepperAxisStepsPerMM(Z_AXIS)) )

#endif

//When pausing, filament is retracted to stop stringing / blobbing.
//This sets the amount of filament in mm's to be retracted
#define PAUSE_RETRACT_FILAMENT_AMOUNT_MM        2.0

//When defined, the Ditto Printing setting is added to General Settings
#define DITTO_PRINT

//When defined, the Z axis is clipped to it's maximum limit
//Applicable to Replicator.  Probably not applicable to ToM/Cupcake due to incorrect length
//in the various .xml's out there
//#define CLIP_Z_AXIS

// Our software variant id for the advanced version command
#define SOFTWARE_VARIANT_ID 0x80

// When defined, acceleration stats are displayed on the LCD screen
//#define ACCEL_STATS

// Disabled SD card folder support owing to a broken SD card detect switch
//#define BROKEN_SD

// Build with nozzle calibration S3G script and help screen to run it
//#define NOZZLE_CALIBRATION_SCRIPT

// Single extruder builds have space for SDHC & FAT-32 support
#if defined(SINGLE_EXTRUDER) || !defined(NOZZLE_CALIBRATION_SCRIPT) || defined(__AVR_ATmega2560__)
#define SD_RAW_SDHC 1
#endif

// When defined, the ability to write an SD card file over S3G is supported
//#define S3G_CAPTURE_2_SD

// When defined, VREF for the Z axis may be set above 40
//#define DIGI_POT_HIGH_Z_VREF

#if defined(BUILD_STATS) && !defined(ESTIMATE_TIME)
#define ESTIMATE_TIME 1
#endif

#endif // BOARDS_MBV40_CONFIGURATION_HH_
