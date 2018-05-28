#include "ArduinoDigitalOutput.hpp"
#include "Arduino.h"

/****ArduinoDigitalOutput****/
ArduinoDigitalOutput::ArduinoDigitalOutput(int pinNumber) :
    IDigitalOutput{pinNumber}
{
    pinMode(this->pinNumber(), OUTPUT);
}

IDigitalOutput &ArduinoDigitalOutput::setState(bool state) {
    this->m_state = state;
    digitalWrite(this->pinNumber(), state);
    return *this;
}

bool ArduinoDigitalOutput::state() {
    return this->m_state;
}
/****End ArduinoDigitalOutput****/

/****ActiveHighDigitalOutput****/
ActiveHighDigitalOutput::ActiveHighDigitalOutput(int pinNumber) :
    ArduinoDigitalOutput{pinNumber}
{
    
}
/****End ActiveHighDigitalOutput****/

/****ActiveLowDigitalOutput****/
ActiveLowDigitalOutput::ActiveLowDigitalOutput(int pinNumber) :
    ArduinoDigitalOutput{pinNumber}
{

}

IDigitalOutput &ActiveLowDigitalOutput::setState(bool state) {
    return ArduinoDigitalOutput::setState(!state);
}

bool ActiveLowDigitalOutput::state() {
    return !ArduinoDigitalOutput::state();
}
/****End ActiveLowDigitalOutput****/

