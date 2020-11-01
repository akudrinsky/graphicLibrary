#include "Text.hpp"
#include "../../engine/engineInterface.hpp"
#include "climits"

namespace kudry
{

TextWindow::TextWindow(const Font* font, const char* textToDraw, const uint8_t textSize)
    :
    font(font),
    text(new char[strnlen(textToDraw, PATH_MAX)]),
    size(textSize),
    coords(0, 0)
{
    strncpy(text, textToDraw, PATH_MAX);
}

TextWindow::~TextWindow()
{
    delete [] text;
}

void TextWindow::SetCoords(const FlatObj& newCoords)
{
    coords = newCoords;
}

bool TextWindow::HandleEvent([[maybe_unused]] Event* event)
{
    return event != nullptr;
}

void TextWindow::Draw(engineInterface* Canvas)
{
    Canvas->DrawText(*this);
}

const Font* TextWindow::GetFont() const
{
    return font;
}

uint8_t TextWindow::GetSize() const
{
    return size;
}

void TextWindow::EmplaceWindow([[maybe_unused]] AbstractWindow* window)
{}

void TextWindow::RemoveWindow([[maybe_unused]] AbstractWindow* window)
{}

}