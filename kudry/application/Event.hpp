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
        Scrollbar,
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
    FlatObj Position;
    ActionType Action;
    MouseEvent(const FlatObj& pos, const ActionType& action);
};

/*--------------------------------------------------------------------------*/

// Desribes all events got from scrollbar
// TODO: make it a user event
class ScrollbarEvent : public Event
{
public:
    double Position;
    ScrollbarEvent(double position);
};

}