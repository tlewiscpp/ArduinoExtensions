#include "ArduinoDigitalInput.hpp"

#include "Arduino.h"


/****ArduinoDigitalInput****/
ArduinoDigitalInput::ArduinoDigitalInput(int pinNumber) :
    IDigitalInput{pinNumber},
    m_isPulledUp{false}
{
    this->setPullUp(false);
}

ArduinoDigitalInput &ArduinoDigitalInput::setPullUp(bool pullUp) {
    this->m_isPulledUp = pullUp;
    if (pullUp) {
        pinMode(this->pinNumber(), INPUT_PULLUP);
    } else {
        pinMode(this->pinNumber(), INPUT);
    }
    return *this;
}

bool ArduinoDigitalInput::isPulledUp() const {
    return this->m_isPulledUp;
}

bool ArduinoDigitalInput::state() {
    return digitalRead(this->pinNumber());
}
/****End ArduinoDigitalInput****/


/****ActiveHighDigitalInput****/
ActiveHighDigitalInput::ActiveHighDigitalInput(int pinNumber) :
    ArduinoDigitalInput{pinNumber}
{

}
/****End ActiveHighDigitalInput****/

/****ActiveLowDigitalInput****/
ActiveLowDigitalInput::ActiveLowDigitalInput(int pinNumber) :
    ArduinoDigitalInput{pinNumber}
{

}

bool ActiveLowDigitalInput::state() {
    return !ArduinoDigitalInput::state();
}

/****ActiveLowDigitalInput****/