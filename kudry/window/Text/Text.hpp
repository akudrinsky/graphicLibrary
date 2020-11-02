#pragma once

#include "../AbstractWindow.hpp"
#include "Font.hpp"
#include "../../simpleGraphics/geometry/geometry.hpp"

namespace kudry
{

class TextWindow : public AbstractWindow 
{
public:
    TextWindow(const Font* font, const char* text, const uint8_t size);

    ~TextWindow();

    void SetCoords(const FlatObj& newCoords);

//    void ChangeFont(const Font* newFont);

//    void ChangeText(const char* newText);

    const Font* GetFont() const;

    uint8_t GetSize() const;

    const char* GetText() const;

    virtual bool HandleEvent([[maybe_unused]] Event* event) override;

    virtual void Draw(engineInterface* Canvas) override;

    virtual void EmplaceWindow(AbstractWindow* window) override;

    virtual void RemoveWindow(AbstractWindow* window) override;

private:
    const Font* font;
    char* text;
    const uint8_t size;
    FlatObj coords;
};

}