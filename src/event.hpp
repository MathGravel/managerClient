#pragma once
#include <string>
#include <numeric>
#include <algorithm>
#include <iostream>
#include "types.hpp"
/**
 *  Event class
 *  @note Based on the requirement "Le gestionnaire ne connaît pas tous les types d’événements.",
 *  it was chosen to give the eventType structure a variable representation, instead of turning the Event class into a Command pattern with subclasses,
 *  or using an known enum as an type identifier.
 *  @copyright Mathieu Gravel
 */
class Event
{
public:
    Event();
    Event(int eventId);
    int getEventId();

private:
    std::string eventType;
    std::string eventInfo;
    int eventIdentifier;
    int workTime;
    friend std::ostream &operator<<(std::ostream &os, Event const &ev)
    {
        os << "EVENT :" << ev.eventType << " " << ev.eventInfo << " " << ev.eventInfo;
        return os;
    }
};