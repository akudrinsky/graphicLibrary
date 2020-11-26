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
        MousePressed,
        MouseReleased,
        MouseMoved,
        Close,
        User,
        #include "UserDefined.def"
    };

    Event();

    struct None
    {};

    struct ClickData 
    {
        FlatObj coord;
    };

    struct UserData
    {
        void* data;
    };

    struct KeyboardData 
    {
        //...
    };

    // Additional information about the event. 
    // Makes sense only when knowing its ID.
    union eventData
    {
        ClickData Click;
        KeyboardData Keyboard;
        None NoData;
        UserData User;
        
        eventData();
    } Data;

//private:
    // Event's type
    EventType ID;
};

}