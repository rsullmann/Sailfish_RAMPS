#####This is a port of the Sailfish Firmware Authored by Dan Newman and Jetty for use on RAMPS hardware on a Mendel with the following configuration:

######20x4 LCD Display connected in 4 bit mode as follows:

LCD_RS_PIN		Pin(PortK,1)//..Digital Pin #63  
LCD_RW_PIN		Pin(PortL,7)//..Digital Pin #42  
LCD_ENABLE_PIN  	Pin(PortK,3)//..Digital Pin #65  
LCD_D0_PIN		Pin(PortF,5)//..Digital Pin #59  
LCD_D1_PIN		Pin(PortK,2)//..Digital Pin #64  
LCD_D2_PIN		Pin(PortL,5)//..Digital Pin #44  
LCD_D3_PIN		Pin(PortK,4)//..Digital Pin #66  

######16 Button Keypad Connected as follows:
INTERFACE_ROW1		Pin(PortA,1) //..Digital Pin #23  
INTERFACE_ROW2		Pin(PortA,3) //..Digital Pin #25  
INTERFACE_ROW3		Pin(PortA,5) //..Digital Pin #27  
INTERFACE_ROW4		Pin(PortA,7) //..Digital Pin #29  
INTERFACE_COL1		Pin(PortC,0) //..Digital Pin #37  
INTERFACE_COL2		Pin(PortC,2) //..Digital Pin #35  
INTERFACE_COL3		Pin(PortC,4) //..Digital Pin #33  
INTERFACE_COL4		Pin(PortC,6) //..Digital Pin #31  

######SDRAMPS Module Connected to AUX-3:
MISO  
MOSI  
Chip Select=D53  
Card Detect=D49  

###### Extruder which uses a Thermistor:

Extruder Power               Pin(PortB,4) //..Digital Pin #10  
Extruder Fan                 Pin(PortH,6) //..Digital Pin #9  
Extruder Thermistor          13 //PortK,5..Analog Pin 13  


######Heated Build Platform using a Thermistor
Heated Build Platform Heat               Pin(PortH,5) //..Digital Pin #8  
Heated build Platform Thermistor         14 //PortK,6...Analog Pin 14  

######Stepper Configuration:
X Axis:  
  Endstop at Maximum  
  1/16th stepping  
  No Digital Pots  

Y Axis  
  Endstop at Minimum  
  1/16 step mode  
  No Digital Pots  

Z Axis  
  Endstop at Maximum  
  Full step mode  
  No Digital Pots   

Extruder  
  Wades Extruder with Makergear Groove Mount Heater  
  1/16 step mode  
  No Digital Pots  


Credit/Attribution:

	This software was ported from the Sailfish Firmware Authored By by Dan Newman and Jetty.
	Only components necessary to get it to function on a RAMPS1.3 Board on a Mendel have been changed.
