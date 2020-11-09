#pragma once

#include "../application/Event.hpp"
#include "../LOGS/logs.hpp"
#include "../engine/settings.hpp"
#include <unordered_set>

namespace kudry
{

class AbstractWindow
{
public:
    virtual ~AbstractWindow() = 0;

    virtual bool HandleEvent([[maybe_unused]] Event* event) = 0;

    virtual void Draw(engineInterface* Canvas) = 0;

    virtual void EmplaceWindow([[maybe_unused]] AbstractWindow* window) = 0;

    virtual void RemoveWindow([[maybe_unused]] AbstractWindow* window) = 0;

protected:
    std::unordered_set<AbstractWindow*> subwindows;
    //std::unordered_set<AbstractComponent*> components;
};

class AbstractComponent
{};

}