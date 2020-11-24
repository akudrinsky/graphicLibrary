#include "Instrument.hpp"

namespace kudry
{

kudry::AbstractWindow* kudry::Instrument::active = nullptr;

void Instrument::SetActive()
{
    active = this;
}

}