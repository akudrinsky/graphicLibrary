#include "Text.hpp"
#include "../../engine/engineInterface.hpp"
#include "climits"
#include <iostream>
#include <cstring>

namespace kudry
{

TextWindow::TextWindow(const Font* font, const std::string& textToDraw, const uint8_t textSize)
    :
    font(font),
    text(textToDraw),
    size(textSize),
    coords(0, 0)
{}

/*--------------------------------------------------------------------------*/

TextWindow::~TextWindow()
{}

/*--------------------------------------------------------------------------*/

void TextWindow::SetCoords(const FlatObj<int>& newCoords)
{
    coords = newCoords;
}

/*--------------------------------------------------------------------------*/

bool TextWindow::HandleEvent([[maybe_unused]] Event* event)
{
    return event != nullptr;
}

/*--------------------------------------------------------------------------*/

void TextWindow::Draw(engineInterface* Canvas)
{
    Canvas->DrawText(this);
}

/*--------------------------------------------------------------------------*/

const Font* TextWindow::GetFont() const
{
    return font;
}

/*--------------------------------------------------------------------------*/

uint8_t TextWindow::GetSize() const
{
    return size;
}

/*--------------------------------------------------------------------------*/

const std::string& TextWindow::GetText() const
{
    return text;
}

/*--------------------------------------------------------------------------*/

void TextWindow::EmplaceWindow([[maybe_unused]] AbstractWindow* window)
{}

/*--------------------------------------------------------------------------*/

void TextWindow::RemoveWindow([[maybe_unused]] AbstractWindow* window)
{}

}