#include "Clickable.hpp"

namespace kudry
{

void ClickableComponent::OnClick()
{
    clickAction_(owner_);
}

void ClickableComponent::OnRelease()
{
    releaseAction_(owner_);
}

ClickableComponent::ClickableComponent(
    Action_t clickAction, 
    Action_t releaseAction,
    AbstractWindow* owner)
    :
    clickAction_(clickAction),
    releaseAction_(releaseAction),
    owner_(owner)
{}



}