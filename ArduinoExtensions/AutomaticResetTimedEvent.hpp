#ifndef AUTOMATICRESETTIMEDEVENT_H
#define AUTOMATICRESETTIMEDEVENT_H

using CallbackFunction = void(*)(); 

class AutomaticResetTimedEvent
{
public:
    AutomaticResetTimedEvent(unsigned long timeout, CallbackFunction callbackFunction);
    AutomaticResetTimedEvent &updateState();
    AutomaticResetTimedEvent &start();
    AutomaticResetTimedEvent &restart();
    AutomaticResetTimedEvent &stop();
    bool isActive() const;

    unsigned long timeout() const;
    AutomaticResetTimedEvent &setTimeout(unsigned long timeout);

    CallbackFunction setCallback(CallbackFunction callbackFunction);
    CallbackFunction callback();

private:   
    unsigned long m_timeout;
    bool m_isActive;
    unsigned long m_startTime;
    CallbackFunction m_callback;
};

#endif //AUTOMATICRESETTIMEDEVENT_H
