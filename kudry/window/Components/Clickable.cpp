#include "Clickable.hpp"
#include <stdexcept>

namespace kudry
{

void ClickableComponent::OnClick()
{
    if (clickAction_ == nullptr)
    {
        LOGS("ERROR: no click function\n")
        throw std::out_of_range("no click function");
    }
    (*clickAction_)(owner_);
}

void ClickableComponent::OnRelease()
{
    if (releaseAction_ == nullptr)
    {
        LOGS("ERROR: no release function\n")
        throw std::out_of_range("no click function");
    }
    (*releaseAction_)(owner_);
}

void ClickableComponent::ChangeClickAction(Action_t newAction)
{
    clickAction_ = newAction;
}

void ClickableComponent::ChangeReleaseAction(Action_t newAction)
{
    releaseAction_ = newAction;
}

ClickableComponent::ClickableComponent(
    Action_t clickAction, 
    Action_t releaseAction,
    AbstractWindow* owner
)   :
    clickAction_(clickAction),
    releaseAction_(releaseAction),
    owner_(owner)
{}



}