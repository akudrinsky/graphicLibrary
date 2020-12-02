#pragma once

#include "../AbstractWindow.hpp"
#include "Font.hpp"
#include "../../simpleGraphics/geometry/geometry.hpp"
#include <string>

namespace kudry
{

// Describes text interface for my library
class TextWindow : public AbstractWindow 
{
public:
    TextWindow(const Font* font, const std::string& text, const uint8_t size);

    ~TextWindow();

    // Sets coordinates of text field
    void SetCoords(const FlatObj<int>& newCoords);

//    void ChangeFont(const Font* newFont);

//    void ChangeText(const char* newText);

    // Returns font of this text
    const Font* GetFont() const;

    // Returns size of this text
    uint8_t GetSize() const;

    // Returns size of this text for const objects
    const std::string& GetText() const;

    virtual bool HandleEvent([[maybe_unused]] Event* event) override;

    virtual void Draw(engineInterface* Canvas) override;

    virtual void EmplaceWindow(AbstractWindow* window) override;

    virtual void RemoveWindow(AbstractWindow* window) override;

private:
    const Font* font;
    std::string text;
    const uint8_t size;
    FlatObj<int> coords;
};

}