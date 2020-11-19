#pragma once

#include <string_view>

namespace kudry
{

// Font interface for my library. Does NOT contain font itself, it only has its name.
// Font will be opened automatically in low-level engine implementation.
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