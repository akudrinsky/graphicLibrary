#pragma once

#include "../simpleGraphics/geometry/geometry.hpp"

namespace kudry
{

enum EventType 
{
    ClickEvent = 0,
    MouseEvent = 1,
    KeyboardEvent = 2,
    IdleEvent = 3,
};

struct Event
{
    EventType eventID;

    struct MouseData 
    {
        FlatObj coord;
    };

    struct ClickData 
    {
        FlatObj coord;
    };

    struct KeyboardData 
    {
        FlatObj coord;
        //...
    };

    union data 
    {
        MouseData Mouse;
        ClickData Click;
        KeyboardData Keyboard;
    };
    
};

}