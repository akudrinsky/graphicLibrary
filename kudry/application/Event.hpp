#pragma once
#include "../simpleGraphics/geometry/geometry.hpp"

namespace kudry
{

struct Event
{
    enum EventType 
    {
        Unknown,
        MouseEvent,
        Close,
    };

    Event();

    EventType ID;

    struct MouseData 
    {
        FlatObj coord;
    };

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
        MouseData Mouse;
        ClickData Click;
        KeyboardData Keyboard;
        None NoData;
        
        eventData();
    } Data;
    
};

}