#include "engineSFML.hpp"
#include "../../LOGS/logs.hpp"
#include "../../Application/SubscriptionManager/SubscriptionManager.hpp"

namespace kudry
{

sf::RenderWindow* engineSFML::windowOS = nullptr;

std::unordered_map<std::string_view, sf::Font*> engineSFML::openedFonts = {};

std::unordered_map<const void*, void*> engineSFML::resources = {};

/*--------------------------------------------------------------------------*/

void engineSFML::NewWindow(AbstractWindow *window)
{
    windows.emplace(window);
}

/*--------------------------------------------------------------------------*/

void engineSFML::DeleteWindow(AbstractWindow *window)
{
    windows.erase(window);
}

/*--------------------------------------------------------------------------*/

bool engineSFML::IsInside(AbstractWindow *window)
{
    return windows.find(window) != windows.end();
}

/*--------------------------------------------------------------------------*/

void engineSFML::Init(const std::string_view& windowName)
{
    windowOS = new sf::RenderWindow(sf::VideoMode::getDesktopMode(), windowName.data());
}

/*--------------------------------------------------------------------------*/

void engineSFML::Destroy() 
{
    windowOS->close();
    for (auto& openedFont : openedFonts) 
    {
        delete openedFont.second;
    }
    delete windowOS;
}

/*--------------------------------------------------------------------------*/

sf::Vector2f engineSFML::changeFlatObj(const FlatObj<int>& size) 
{
    return sf::Vector2f((float)size.x, (float)size.y);
}

/*--------------------------------------------------------------------------*/

sf::Color engineSFML::changeColor(const Color& color) 
{
    return sf::Color(
        (sf::Uint8)color.Red, 
        (sf::Uint8)color.Green, 
        (sf::Uint8)color.Blue
    );
}

/*--------------------------------------------------------------------------*/

void engineSFML::DrawRect(
    const RectangleShape rect_, 
    const Color& color)
{
    sf::RectangleShape rect(changeFlatObj(rect_.GetSize()));
    rect.setFillColor(changeColor(color));
    rect.setPosition((float)rect_.GetOrigin().x, (float)rect_.GetOrigin().y);

    windowOS->draw(rect);
}

/*--------------------------------------------------------------------------*/

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
        text->setPosition(
            0, 
            static_cast<float>(-offset * text->getGlobalBounds().height)
        );

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

/*--------------------------------------------------------------------------*/

uint8_t engineSFML::Run()
{
    while (windowOS->isOpen()) 
    {
        sf::Event event;
        Event* myEvent;

        while (windowOS->pollEvent(event)) 
        {
            myEvent = createMyEvent(event);
            //SubscriptionManager::Send(sysWindow, &myEvent);

            for (auto window : windows) 
                window->HandleEvent(myEvent);

            if (myEvent->GetEventType() == Event::Close)
            {
                windowOS->close();
                LOGS("OS application window was closed\n")
            }
            delete myEvent;
        }

        for (auto window : windows) 
        {
            window->Draw(this);
        }
        windowOS->display();
    }
    
    return 0;
}


/*--------------------------------------------------------------------------*/

Event* engineSFML::createMyEvent(const sf::Event& sfmlEvent)
{
    Event* myEvent = nullptr;
    switch (sfmlEvent.type)
    {
        case sf::Event::Closed:
        {
            myEvent = new Event(Event::Close);
            LOGS("Close event\n")
            break;
        }
        case sf::Event::MouseButtonPressed:
        {
            myEvent = new MouseEvent(
                FlatObj<int>(
                    sfmlEvent.mouseButton.x, 
                    sfmlEvent.mouseButton.y), 
                MouseEvent::WasPressed);
            break;
        }
        case sf::Event::MouseButtonReleased:
        {
            myEvent = new MouseEvent(
                FlatObj<int>(
                    sfmlEvent.mouseButton.x, 
                    sfmlEvent.mouseButton.y), 
                MouseEvent::WasReleased);
            break;
        }
        case sf::Event::MouseMoved:                
        {
            myEvent = new MouseEvent(
                FlatObj<int>(
                    sfmlEvent.mouseButton.x, 
                    sfmlEvent.mouseButton.y), 
                MouseEvent::WasMoved);
            break;
        }
        // TODO: more events
        default: 
        {
            myEvent = new Event;
        }
    }
    return myEvent;
}

/*--------------------------------------------------------------------------*/

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

/*--------------------------------------------------------------------------*/

void engineSFML::DrawPicture(const Picture* picture)
{
    //LOGS("Drawing pict")
    sf::Texture texture;
    texture.create(picture->GetSize().x, picture->GetSize().y);
    texture.update(picture->GetRawData());

    sf::Sprite sprite(texture);

    sprite.setPosition(picture->GetOrigin().x, picture->GetOrigin().y);

    windowOS->draw(sprite);
}

}