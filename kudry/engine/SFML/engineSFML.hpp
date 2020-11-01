#pragma once

#include <SFML/Graphics.hpp>
#include <unordered_set>
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

    virtual void Init(const char* windowName) override;

    virtual void Destroy() override;

    virtual Event* PollEvent() override;

    virtual uint8_t Run(std::unordered_set<AbstractWindow*>& windows) override;

private:

    static sf::RenderWindow* windowOS;

    static sf::Vector2f changeFlatObj(const FlatObj& coords);

    static sf::Color changeColor(const Color& color);

};

};