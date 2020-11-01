#pragma once

#include <SFML/Graphics.hpp>
#include <unordered_set>
#include <unordered_map>
#include "../engineInterface.hpp"

namespace kudry
{

class engineSFML : public engineInterface {
public:
    virtual void DrawRect
    (
        const FlatObj& coords, 
        const FlatObj& size, 
        const Color& color
    ) override;

    virtual void DrawText(const TextWindow& textToDraw) override;

    virtual void Init(const std::string_view& windowName) override;

    virtual void Destroy() override;

    virtual Event* PollEvent() override;

    virtual uint8_t Run(std::unordered_set<AbstractWindow*>& windows) override;

private:

    static sf::RenderWindow* windowOS;

    static std::unordered_map<std::string_view, sf::Font*> openedFonts;

    static sf::Vector2f changeFlatObj(const FlatObj& coords);

    static sf::Color changeColor(const Color& color);

};

};