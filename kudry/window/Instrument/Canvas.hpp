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
        const FlatObj<int>& position, 
        const FlatObj<int>& size, 
        const Color& color = Color::WhiteColor
    );

    virtual bool HandleEvent([[maybe_unused]] Event* event) override;

    void LoadFromFile(const char* filename);

    void SaveToFile(const char* filename) const;

    const Picture& GetPicture() const;

    void SetOrigin(const FlatObj<int>& origin);

    void SetSize(const FlatObj<int>& size);

    void SetColor(const Color& clr);

    virtual void Draw(engineInterface* engine) override;

    virtual void EmplaceWindow([[maybe_unused]] AbstractWindow* window) override;

    virtual void RemoveWindow([[maybe_unused]] AbstractWindow* window) override;

private:
    Picture picture;
};

}