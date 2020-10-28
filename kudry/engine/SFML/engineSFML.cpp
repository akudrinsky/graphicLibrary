#include "engineSFML.hpp"

namespace kudry
{

sf::RenderWindow* engineSFML::windowOS = nullptr;

void engineSFML::Init(const char* windowName)
{
    windowOS = new sf::RenderWindow(sf::VideoMode::getDesktopMode(), windowName);
}

void engineSFML::Destroy() {
    delete windowOS;
}

sf::Vector2f engineSFML::changeFlatObj(const FlatObj& size) {
    return sf::Vector2f(size.x, size.y);
}

sf::Color engineSFML::changeColor(const Color& color) {
    return sf::Color(color.Red, color.Green, color.Blue);
}

void engineSFML::DrawRect
(
    const FlatObj& coords, 
    const FlatObj& size, 
    const Color& color
)
{
    sf::RectangleShape rect(changeFlatObj(size));
    rect.setFillColor(changeColor(color));
    rect.setPosition(coords.x, coords.y);

    windowOS->draw(rect);
}

};