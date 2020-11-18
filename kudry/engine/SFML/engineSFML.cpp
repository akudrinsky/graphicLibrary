#include "engineSFML.hpp"
#include "../../LOGS/logs.hpp"
#include "../../Application/SubscriptionManager/SubscriptionManager.hpp"

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
    const RectangleShape rect_, 
    const Color& color
)
{
    sf::RectangleShape rect(changeFlatObj(rect_.GetSize()));
    rect.setFillColor(changeColor(color));
    rect.setPosition((float)rect_.GetOrigin().x, (float)rect_.GetOrigin().y);

    windowOS->draw(rect);
}

[[deprecated]]
Event* engineSFML::PollEvent()
{
    Event* myEvent = new Event;

    sf::Event SFMLevent;
    windowOS->pollEvent(SFMLevent);

    switch (SFMLevent.type) 
    {
    case sf::Event::MouseButtonPressed:
        myEvent->ID = kudry::Event::MousePressed;
        myEvent->Data.Click.coord = FlatObj(SFMLevent.mouseButton.x, SFMLevent.mouseButton.y);
        break;

    case sf::Event::MouseButtonReleased:
        myEvent->ID = kudry::Event::MouseReleased;
        myEvent->Data.Click.coord = FlatObj(SFMLevent.mouseButton.x, SFMLevent.mouseButton.y);
        break;
    
    case sf::Event::Closed:
        LOGS("Closing event\n")
        myEvent->ID = kudry::Event::Close;
        break;
    
    default:
        break;
    }

    return myEvent;
    return nullptr;
}



void engineSFML::DrawText(
    const TextWindow* textToDraw, 
    const RectangleShape* canvas,
    const Color* backgroundColor,
    double offset
)
{
    createTextObj(textToDraw);

    if (canvas == nullptr)
    {
        windowOS->draw(*reinterpret_cast<sf::Text*>(resources.at(textToDraw)));
    }
    else
    {
        LOGS("position in drawer: %lf", offset)
        auto text = reinterpret_cast<sf::Text*>(resources.at(textToDraw));
        text->setPosition(0, static_cast<float>(- offset * text->getGlobalBounds().height));

        sf::RenderTexture rect;

        rect.create(
            static_cast<unsigned int>(canvas->GetSize().x), 
            static_cast<unsigned int>(canvas->GetSize().y)
        );
        rect.clear(changeColor(*backgroundColor));
        rect.draw(*text);
        rect.display();

        sf::Sprite viewSprite(rect.getTexture());
        viewSprite.setPosition(
            static_cast<unsigned int>(canvas->GetOrigin().x), 
            static_cast<unsigned int>(canvas->GetOrigin().y)
        );

        windowOS->draw(viewSprite);
    }
    
    //LOGS("INFO >>> Text <%s> was written\n", textToDraw->GetText())
}

uint8_t engineSFML::Run(std::unordered_set<AbstractWindow*>& windows)
{
    while (windowOS->isOpen()) 
    {
        sf::Event event;
        kudry::Event myEvent;

        while (windowOS->pollEvent(event)) 
        {
            switch (event.type)
            {
                case sf::Event::Closed:
                {
                    LOGS("Close event\n")
                    myEvent.ID = kudry::Event::Close;
                    myEvent.Data.NoData = {};
                    break;
                }
                case sf::Event::MouseButtonPressed:
                {
                    myEvent.ID = kudry::Event::MousePressed;
                    myEvent.Data.Click.coord = 
                        kudry::FlatObj(event.mouseButton.x, event.mouseButton.y);
                    break;
                }
                case sf::Event::MouseButtonReleased:
                {
                    myEvent.ID = kudry::Event::MouseReleased;
                    myEvent.Data.Click.coord = 
                        kudry::FlatObj(event.mouseButton.x, event.mouseButton.y);
                    break;
                }
                // TODO: more events
                default: 
                {
                    myEvent.ID = kudry::Event::Unknown;
                    myEvent.Data.NoData = {};
                    break;
                }
            }

            //SubscriptionManager::Send(sysWindow, &myEvent);

            for (auto window : windows) 
                window->HandleEvent(&myEvent);

            if (myEvent.ID == kudry::Event::Close)
            {
                windowOS->close();
                LOGS("OS application window was closed\n")
            }
        }

        for (auto window : windows) 
        {
            window->Draw(this);
        }
        windowOS->display();
    }
    
    return 0;
}

void engineSFML::createTextObj(const TextWindow* textToDraw)
{
    auto fontName = textToDraw->GetFont()->getPathToFont();
    if (!openedFonts.count(fontName)) 
    {
        auto font = new sf::Font();
        if (!font->loadFromFile(std::string(fontName)))
        {
            throw std::out_of_range("unable to load font");
        }

        openedFonts.emplace(fontName, font);
    }

    // TODO: check if works
    if (!resources.count(textToDraw))
    {
        //LOGS("string: <%s>\n", textToDraw->GetText())
        LOGS("font: <%s>\n", (*openedFonts.at(fontName)).getInfo().family.c_str())
        LOGS("size: <%d>\n", textToDraw->GetSize())
        resources.emplace(
            textToDraw, 
            new sf::Text(
                textToDraw->GetText(), 
                *openedFonts.at(fontName), 
                textToDraw->GetSize()
            )
        );
    }
}

}