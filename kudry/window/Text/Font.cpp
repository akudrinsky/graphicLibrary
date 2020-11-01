#include "Font.hpp"

namespace kudry
{

Font::Font(const std::string_view& fontPath)
    :
    pathToFont(fontPath)
{}

Font::~Font()
{}

const std::string_view& Font::getPathToFont() const
{
    return pathToFont;
}

}