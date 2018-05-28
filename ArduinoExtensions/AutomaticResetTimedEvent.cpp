#include "AutomaticResetTimedEvent.hpp"

#include "Arduino.h"
#include <limits.h>

AutomaticResetTimedEvent::AutomaticResetTimedEvent(unsigned long timeout, CallbackFunction callbackFunction) :
    m_timeout{0},
    m_isActive{false},
    m_startTime{ULONG_MAX},
    m_callback{nullptr}
{
    this->setTimeout(timeout);
    this->setCallback(callbackFunction);
}

AutomaticResetTimedEvent &AutomaticResetTimedEvent::updateState() {
    if (!this->m_isActive) {
        return *this;
    }

    if ( (millis() - this->m_startTime) >= this->m_timeout) {
        if (this->m_callback) { this->m_callback(); }
        this->m_startTime = millis();
    }
    return *this;
}

AutomaticResetTimedEvent &AutomaticResetTimedEvent::setTimeout(unsigned long timeout) {
    this->m_timeout = timeout;
    return *this;
}

unsigned long AutomaticResetTimedEvent::timeout() const {
    return this->m_timeout;
}

AutomaticResetTimedEvent &AutomaticResetTimedEvent::start() {
    this->m_isActive = true;
    if (this->m_startTime == ULONG_MAX) {
        this->m_startTime = millis();
    }
    this->updateState();
    return *this;
}

AutomaticResetTimedEvent &AutomaticResetTimedEvent::restart() {
    this->m_startTime = millis();
    this->start();
    return *this;
}

AutomaticResetTimedEvent &AutomaticResetTimedEvent::stop() {
    this->m_isActive = false;
    this->m_startTime = ULONG_MAX;
    return *this;
}

bool AutomaticResetTimedEvent::isActive() const {
    return this->m_isActive;
}

CallbackFunction AutomaticResetTimedEvent::setCallback(CallbackFunction callbackFunction) {
    auto callback = this->m_callback;
    this->m_callback = callbackFunction;
    return callback;
}

CallbackFunction AutomaticResetTimedEvent::callback() {
    return this->m_callback;
}
