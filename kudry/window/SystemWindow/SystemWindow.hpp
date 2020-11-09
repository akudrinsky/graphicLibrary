#pragma once

#include "../AbstractWindow.hpp"

namespace kudry
{

class SystemWindow : public AbstractWindow
{
public:
    SystemWindow();

    virtual ~SystemWindow() override;

    virtual bool HandleEvent([[maybe_unused]] Event* event) override;

    virtual void Draw([[maybe_unused]] engineInterface* Canvas) override;

    virtual void EmplaceWindow([[maybe_unused]] AbstractWindow* window) override;

    virtual void RemoveWindow([[maybe_unused]] AbstractWindow* window) override;
};

}