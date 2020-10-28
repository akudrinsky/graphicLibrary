#pragma once

#include "../application/Event.hpp"
#include "../engine/settings.hpp"
#include <unordered_set>

namespace kudry
{

class AbstractWindow
{
public:
    virtual ~AbstractWindow() = 0;

    virtual bool HandleEvent(Event* event) = 0;

    virtual void Draw() = 0;

    virtual void EmplaceWindow(AbstractWindow* window) = 0;

    virtual void RemoveWindow(AbstractWindow* window) = 0;

protected:
    AbstractWindow* parent;
    std::unordered_set<AbstractWindow*> subwindows;
};

};