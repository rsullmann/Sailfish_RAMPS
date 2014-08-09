
#include "Interface.hh"
#include "InterfaceBoard.hh"
#include "Configuration.hh"
#if defined(HAS_I2C_LCD)
#include "LiquidCrystalSerial_I2C.hh"
#elif defined(HAS_VIKI_INTERFACE)
#include "VikiInterface.hh"
#endif

// TODO: Make this a proper module.
#if defined HAS_INTERFACE_BOARD

namespace interface {


LiquidCrystalSerial* lcd;
InterfaceBoard* board;


void init(InterfaceBoard* board_in, LiquidCrystalSerial* lcd_in) {
    board = board_in;
    lcd = lcd_in;
}

void pushScreen(Screen* newScreen) {
        board->pushScreen(newScreen);
}

void pushNoUpdate(Screen *newScreen){
	board->pushNoUpdate(newScreen);
}

void popScreen() {
        board->popScreen();
}

bool isButtonPressed(ButtonArray::ButtonName button) {
        return board->isButtonPressed(button);
}

void doInterrupt() {
        board->doInterrupt();
}

micros_t getUpdateRate() {
        return board->getUpdateRate();
}

void doUpdate() {
        board->doUpdate();
}

/*
void setLEDs(bool on){
	board->setLED(0,on);
	board->setLED(1,on);
}
*/

}

#endif