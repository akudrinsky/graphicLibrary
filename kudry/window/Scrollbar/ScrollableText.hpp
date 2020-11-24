#include "../RectangleWindow/RectangleWindow.hpp"
#include "../Text/Text.hpp"
#include "Scrollbar.hpp"

namespace kudry
{

class ScrollableText : public RectangleWindow
{
public:
    ScrollableText(
        const TextWindow& fulltext, 
        const FlatObj& center, 
        const FlatObj& size, 
        const Color& backgroundColor = Color::BlackColor
    );

    virtual ~ScrollableText() override;

    virtual bool HandleEvent([[maybe_unused]] Event* event) override;

    virtual void Draw(engineInterface* Canvas) override;

    // Makes ScrollableText able to recieve events from Scrollbar
    void Attach(Scrollbar* manager);

private:
    TextWindow fulltext;
    double position;
};


}