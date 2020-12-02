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
    // Adds window to set of attached windows
    virtual void NewWindow(AbstractWindow* window) override;

    // Deletes window from set of attached windows
    virtual void DeleteWindow(AbstractWindow* window) override;

    // Check if window is attached
    virtual bool IsInside(AbstractWindow* window) override;

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

    virtual void DrawPicture(const Picture* picture) override;

    virtual void Init(const std::string_view& windowName) override;

    virtual void Destroy() override;

    virtual uint8_t Run() override;

private:
    WindowContainer windows;

    static sf::RenderWindow* windowOS;

    Event* createMyEvent(const sf::Event& sfmlEvent);

    static std::unordered_map<std::string_view, sf::Font*> openedFonts;

    static std::unordered_map<const void*, void*> resources;

    static sf::Vector2f changeFlatObj(const FlatObj<int>& coords);

    static sf::Color changeColor(const Color& color);

    void createTextObj(const TextWindow* textToDraw);

    sf::RenderTexture* textureByCanvas(const Canvas* canvas);

    sf::Sprite spriteByCanvas(const Canvas* canvas);

    /*
    void createLine(
        const Color& clr,
        Thickness_t thickness,
        const FlatObj<int>& from,
        const FlatObj<int>& to
    );
    */

};

}