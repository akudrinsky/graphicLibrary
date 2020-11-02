#include "engineSFML.hpp"
#include "../../LOGS/logs.hpp"

namespace kudry
{

sf::RenderWindow* engineSFML::windowOS = nullptr;

std::unordered_map<std::string_view, sf::Font*> engineSFML::openedFonts = {};

std::unordered_map<const void*, void*> engineSFML::resources = {};

void engineSFML::Init(const std::string_view& windowName)
{
    windowOS = new sf::RenderWindow(sf::VideoMode::getDesktopMode(), windowName.data());
}

void engineSFML::Destroy() 
{
    windowOS->close();
    for (auto& openedFont : openedFonts) 
    {
        delete openedFont.second;
    }
    delete windowOS;
}

sf::Vector2f engineSFML::changeFlatObj(const FlatObj& size) 
{
    return sf::Vector2f((float)size.x, (float)size.y);
}

sf::Color engineSFML::changeColor(const Color& color) 
{
    return sf::Color(
        (sf::Uint8)color.Red, 
        (sf::Uint8)color.Green, 
        (sf::Uint8)color.Blue
    );
}

void engineSFML::DrawRect(
    const FlatObj& coords, 
    const FlatObj& size, 
    const Color& color
)
{
    sf::RectangleShape rect(changeFlatObj(size));
    rect.setFillColor(changeColor(color));
    rect.setPosition((float)coords.x, (float)coords.y);

    windowOS->draw(rect);
}

Event* engineSFML::PollEvent()
{
    Event* myEvent = new Event;

    sf::Event SFMLevent;
    windowOS->pollEvent(SFMLevent);

    switch (SFMLevent.type) 
    {
    case sf::Event::MouseButtonPressed:
        myEvent->ID = kudry::Event::MouseEvent;
        myEvent->Data.Mouse.coord = FlatObj(SFMLevent.mouseButton.x, SFMLevent.mouseButton.y);
        break;
    
    case sf::Event::Closed:
        LOGS("Closing event\n")
        myEvent->ID = kudry::Event::Close;
        break;
    
    default:
        break;
    }

    return myEvent;
}

void engineSFML::DrawText(const TextWindow* textToDraw)
{
    auto fontName = textToDraw->GetFont()->getPathToFont();
    if (!openedFonts.count(fontName)) 
    {
        auto font = new sf::Font();
        if (!font->loadFromFile(std::string(fontName)))
        {
            throw std::out_of_range("unable to load font");
        }

        openedFonts.emplace(textToDraw->GetFont()->getPathToFont(), font);
    }

    // TODO: check if works
    if (!resources.count(textToDraw))
    {
        resources.emplace(
            textToDraw, 
            new sf::Text(
                textToDraw->GetText(), 
                *openedFonts.at(fontName), 
                textToDraw->GetSize()
            )
        );
    }

    windowOS->draw(*reinterpret_cast<sf::Text*>(resources.at(textToDraw)));
    LOGS("INFO >>> Text <%s> was written\n", textToDraw->GetText())

}

uint8_t engineSFML::Run(std::unordered_set<AbstractWindow*>& windows)
{
    while (windowOS->isOpen()) 
    {
        sf::Event event;
        while (windowOS->pollEvent(event)) 
        {
            
        }

        for (auto window : windows) 
        {
            window->Draw(this);
        }
        windowOS->display();
    }
    
    return 0;
}

}