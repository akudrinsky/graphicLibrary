#pragma once

#include "Instrument.hpp"
#include "../RectangleButton/RectangleButton.hpp"
#include "../Components/Shapes/Picture.hpp"

namespace kudry
{

// Class that describes canvas for all instruments.
class Canvas : public AbstractWindow
{
public:
    Canvas(
        const FlatObj& position, 
        const FlatObj& size, 
        const Color& color = Color::DarkGreyColor
    );

    virtual bool HandleEvent([[maybe_unused]] Event* event) override;

    void LoadFromFile(const char* filename);

    void SaveToFile(const char* filename);

    // virtual void Draw(engineInterface* engine) override;
private:
    Picture picture;
};

}