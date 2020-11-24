#pragma once
#include "../simpleGraphics/geometry/geometry.hpp"

namespace kudry
{

// Structure with all events (including system and user ones)
struct Event
{
    // Possible types of an event
    enum EventType 
    {
        Unknown,
        MousePressed,
        MouseReleased,
        MouseMoved,
        Close,
        User,
    };

    Event();

    // Event's type
    EventType ID;

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
    
};

}