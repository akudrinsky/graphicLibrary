#include "SystemWindow.hpp"

namespace kudry
{

SystemWindow::SystemWindow()
{}

SystemWindow::~SystemWindow()
{}

bool SystemWindow::HandleEvent([[maybe_unused]] Event* event)
{
    return false;
}

void SystemWindow::Draw([[maybe_unused]] engineInterface* Canvas)
{}

void SystemWindow::EmplaceWindow([[maybe_unused]] AbstractWindow* window)
{}

void SystemWindow::RemoveWindow([[maybe_unused]] AbstractWindow* window)
{}

};