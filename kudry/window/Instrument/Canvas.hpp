#pragma once

#include "Instrument.hpp"
#include "../RectangleButton/RectangleButton.hpp"

namespace kudry
{

// Class that describes canvas for all instruments.
class Canvas : public RectangleWindow
{
public:
    virtual bool HandleEvent([[maybe_unused]] Event* event) override;

    // virtual void Draw(engineInterface* engine) override;
private:
};

}