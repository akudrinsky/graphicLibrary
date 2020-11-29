#include "Instrument.hpp"
#include "canvasEvents.hpp"

namespace kudry
{

/*--------------------------------------------------------------------------*/

AbstractInstrument* AbstractInstrument::active = nullptr;

/*--------------------------------------------------------------------------*/

void AbstractInstrument::SetActive()
{
    active = this;
}

/*--------------------------------------------------------------------------*/

AbstractInstrument* AbstractInstrument::GetActive()
{
    return active;
}

/*--------------------------------------------------------------------------*/



}