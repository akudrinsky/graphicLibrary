#pragma once

#include <string_view>

namespace kudry
{

class Font 
{
public:
    explicit Font(const std::string_view& pathToFont);

    ~Font();

    const std::string_view& getPathToFont() const;

private:
    std::string_view pathToFont;
};

}