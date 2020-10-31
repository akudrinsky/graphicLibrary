#pragma once

#include <SFML/Graphics.hpp>
#include <unordered_set>
#include "../engineInterface.hpp"

namespace kudry
{

class engineSFML : public engineInterface {
public:
    static void DrawRect
    (
        const FlatObj& coords, 
        const FlatObj& size, 
        const Color& color
    );

    static void DrawText
    (
        const FlatObj& coords, 
        const Color& color
    );

    static void Init(const char* windowName);

    static void Destroy();

    static void Display();

    static Event* PollEvent();

    static uint8_t Run(std::unordered_set<AbstractWindow*>& windows);

private:

    static sf::RenderWindow* windowOS;

    static sf::Vector2f changeFlatObj(const FlatObj& coords);

    static sf::Color changeColor(const Color& color);

};

};