#include "Instrument.hpp"

namespace kudry
{

kudry::Instrument* kudry::AbstractWindow::active = nullptr;

void Instrument::SetActive()
{
    active = this;
}

}