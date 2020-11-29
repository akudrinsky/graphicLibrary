#include "../RectangleWindow/RectangleWindow.hpp"
#include "../RectangleButton/RectangleButton.hpp"

namespace kudry
{

// Scrollbar interface. If somebody wants to recieve events from scrollbar, 
// it needs to subsribe for it (see ScrollableText::Attach method)
class Scrollbar : public AbstractWindow
{
public:
    Scrollbar(
        const FlatObj& origin, 
        const FlatObj& size, 
        const Color& endsColor,
        const Color& middleColor
    );

    //SetScrollable(const )

    // Sets step with wich buttons influence position of scrollbar.
    void SetStep(const double& newStep);

    virtual ~Scrollbar() override;

    virtual bool HandleEvent([[maybe_unused]] Event* event) override;

    virtual void Draw(engineInterface* Canvas) override;

    virtual void EmplaceWindow([[maybe_unused]] AbstractWindow* window) override;

    virtual void RemoveWindow([[maybe_unused]] AbstractWindow* window) override;

private:
    class upperButton : public RectangleButton
    {
    public:
        upperButton(
            const FlatObj& center, 
            const FlatObj& size, 
            const Color& backgroundColor,
            Scrollbar* scrlbar
        );
        virtual void OnClick() override;
        virtual void OnRelease() override;
    private:
        Scrollbar* scrlbar;
    };

    class lowerButton : public RectangleButton
    {
    public:
        lowerButton(
            const FlatObj& center, 
            const FlatObj& size, 
            const Color& backgroundColor,
            Scrollbar* scrlbar
        );
        virtual void OnClick() override;
        virtual void OnRelease() override;
    private:
        Scrollbar* scrlbar;
    };

    class middleButton : public RectangleButton
    {
    public:
        middleButton(
            const FlatObj& center, 
            const FlatObj& size, 
            const Color& backgroundColor,
            Scrollbar* scrlbar
        );
        virtual void OnClick() override;
        virtual void OnRelease() override;
        virtual bool HandleEvent(Event* event) override;
    private:
        Scrollbar* scrlbar;
        // !!! ERROR: May be pointer to freed space !!!
        const FlatObj* clickData;
    };

    void SendPosition();

    double position;
    double step;

    upperButton toUpper;
    lowerButton toLower;
    middleButton middle;
};

}