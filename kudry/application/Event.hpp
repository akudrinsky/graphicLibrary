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
        User,
    };

    Event();

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