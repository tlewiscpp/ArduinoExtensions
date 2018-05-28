#ifndef IOPIN_H
#define IOPIN_H

class IOPin
{
public:
    inline explicit IOPin(int pinNumber) :
        m_pinNumber{0}
    {
        this->setPinNumber(pinNumber);
    }
    inline IOPin &setPinNumber(int pinNumber) { this->m_pinNumber = pinNumber; return *this; }
    inline int pinNumber() const { return this->m_pinNumber; }
private:
    int m_pinNumber;
};


class IDigitalInput : public IOPin
{
public:
    inline explicit IDigitalInput(int pinNumber) : IOPin{pinNumber} {}
    virtual bool state() = 0;
};

class IDigitalOutput : public IOPin
{
public:
    inline explicit IDigitalOutput(int pinNumber) : IOPin{pinNumber} {}
    virtual IDigitalOutput &setState(bool state) = 0;
    virtual bool state() = 0;
};


#endif //IOPIN_H