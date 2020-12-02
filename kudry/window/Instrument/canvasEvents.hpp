#pragma once

#include "../../Application/EventTypes/UserEvent.hpp"
#include "../Components/Shapes/Picture.hpp"
#include "Canvas.hpp"
#include "Instrument.hpp"

namespace kudry
{

class CanvasEvent : public UserEvent
{
public:
    FlatObj pos;
    Picture* pict;
    MouseEvent::ActionType act;
};

}