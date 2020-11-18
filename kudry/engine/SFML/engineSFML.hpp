#pragma once

#include <SFML/Graphics.hpp>
#include <unordered_set>
#include <unordered_map>
#include "../engineInterface.hpp"

template<> 
struct std::hash<void*> {
    size_t operator()(const void* &k) {
        return reinterpret_cast<size_t>(k);
    }
};

namespace kudry
{

class engineSFML : public engineInterface 
{
public:
    virtual void DrawRect(
        const RectangleShape rect, 
        const Color& color
    ) override;

    virtual void DrawText(
        const TextWindow* textToDraw, 
        const RectangleShape* canvas = nullptr,
        const Color* backgroundColor = nullptr,
        double offset = 0.0
    ) override;

    virtual void Init(const std::string_view& windowName) override;

    virtual void Destroy() override;

    virtual Event* PollEvent() override;

    virtual uint8_t Run(std::unordered_set<AbstractWindow*>& windows) override;

private:

    static sf::RenderWindow* windowOS;

    static std::unordered_map<std::string_view, sf::Font*> openedFonts;

    static std::unordered_map<const void*, void*> resources;

    static sf::Vector2f changeFlatObj(const FlatObj& coords);

    static sf::Color changeColor(const Color& color);

    void createTextObj(const TextWindow* textToDraw);

};

}