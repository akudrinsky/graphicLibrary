#pragma once

#include "../simpleGraphics/geometry/geometry.hpp"

namespace kudry
{

// Structure with all events (including system and user ones)
class Event
{
public:
    // Possible types of an event
    enum EventType 
    {
        Unknown,
        Mouse,
        Keyboard,
        Close,
        User,
        Canvas,
    };

    EventType GetEventType() const;

    Event();

    ~Event();

    Event(EventType ID);
private:
    // Event's type
    EventType ID;
};

/*--------------------------------------------------------------------------*/

// Desribes all events got from mouse
class MouseEvent : public Event
{
public:
    enum ActionType
    {
        WasPressed,
        WasReleased,
        WasMoved,
    };
    FlatObj<int> Position;
    ActionType Action;
    MouseEvent(const FlatObj<int>& pos, const ActionType& action);
};

}