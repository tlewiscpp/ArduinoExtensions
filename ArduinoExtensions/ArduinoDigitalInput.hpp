#ifndef ARDUINODIGITALINPUT_H
#define ARDUINODIGITALINPUT_H

#include "IOPin.hpp"

class ArduinoDigitalInput : public IDigitalInput
{
public:
    explicit ArduinoDigitalInput(int pinNumber);
    
    virtual bool state() override;
    ArduinoDigitalInput &setPullUp(bool pullUp);
    bool isPulledUp() const;

private:
    bool m_isPulledUp;
};

class ActiveHighDigitalInput : public ArduinoDigitalInput
{
public:
    explicit ActiveHighDigitalInput(int pinNumber);
    bool state() override;
};

class ActiveLowDigitalInput : public ArduinoDigitalInput
{
public:
    explicit ActiveLowDigitalInput(int pinNumber);
    bool state() override;

private:
    bool m_isPulledUp;
};

#endif //ARDUINODIGITALINPUT_H
