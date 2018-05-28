#ifndef ARDUINODIGITALOUTPUT_H
#define ARDUINODIGITALOUTPUT_H

#include "IOPin.hpp"

class ArduinoDigitalOutput : public IDigitalOutput
{
public:
    explicit ArduinoDigitalOutput(int pinNumber);
    virtual IDigitalOutput &setState(bool state) override;
    virtual bool state() override;

private:
    bool m_state;
};

class ActiveHighDigitalOutput : public ArduinoDigitalOutput
{
public:
    explicit ActiveHighDigitalOutput(int pinNumber);
};

class ActiveLowDigitalOutput : public ArduinoDigitalOutput
{
public:
    explicit ActiveLowDigitalOutput(int pinNumber);
    virtual IDigitalOutput &setState(bool state) override;
    virtual bool state() override;
};

#endif //ARDUINODIGITALOUTPUT_H
