#pragma once
#include "../simpleGraphics/geometry/geometry.hpp"

namespace kudry
{

struct Event
{
    enum EventType 
    {
        Unknown,
        MousePressed,
        MouseReleased,
        Close,
    };

    Event();

    EventType ID;

    struct None
    {};

    struct ClickData 
    {
        FlatObj coord;
    };

    struct KeyboardData 
    {
        //...
    };

    union eventData
    {
        ClickData Click;
        KeyboardData Keyboard;
        None NoData;
        
        eventData();
    } Data;
    
};

}