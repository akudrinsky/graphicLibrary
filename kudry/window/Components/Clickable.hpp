#include "../AbstractWindow.hpp"
#include "../../simpleGraphics/geometry/geometry.hpp"
#include <functional> // TODO: my std::function

namespace kudry
{

class ClickableComponent
{
public:
    typedef void (*Action_t)(AbstractWindow*);

    ClickableComponent() = delete;

    ClickableComponent(
        Action_t clickAction, 
        Action_t releaseAction,
        AbstractWindow* owner
    );

    void OnClick();
    void OnRelease();

private:
    Action_t clickAction_;
    Action_t releaseAction_;
    AbstractWindow* owner_;
};

}