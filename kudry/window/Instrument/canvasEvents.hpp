#pragma once

#include "../../Application/EventTypes/UserEvent.hpp"
#include "Canvas.hpp"
#include "Instrument.hpp"

namespace kudry
{

class CanvasEvent : public UserEvent
{
public:
    FlatObj pos;
    class Canvas* canvas;
    MouseEvent::ActionType act;
};

}