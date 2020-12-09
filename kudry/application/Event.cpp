#include "Event.hpp"

namespace kudry
{

Event::Event()
    :
    ID(Unknown)
{}

/*--------------------------------------------------------------------------*/

Event::~Event()
{}

/*--------------------------------------------------------------------------*/

Event::Event(EventType ID)
    :
    ID(ID)
{}

/*--------------------------------------------------------------------------*/

Event::EventType Event::GetEventType() const
{
    return ID;
}

/*--------------------------------------------------------------------------*/

MouseEvent::MouseEvent(const FlatObj<int> &pos, const MouseEvent::ActionType &action)
    :
    Event(Mouse),
    Position(pos),
    Action(action)
{}

}