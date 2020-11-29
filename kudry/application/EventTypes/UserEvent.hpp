#pragma once

#include "../Event.hpp"

namespace kudry
{

// All non-standard events must be inherited from this class. 
// This guarantees that event's ID in base class is correct.
class UserEvent : public Event
{
public:
    UserEvent();
};

}