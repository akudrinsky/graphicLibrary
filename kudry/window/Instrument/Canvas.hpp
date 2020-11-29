#include "../AbstractWindow.hpp"

namespace kudry
{

// Class that describes functionality, that every instrument must have.
// Important: all instruments have an active one. It is the one that acts on canvas. 
class AbstractInstrument : AbstractWindow
{
public:
    void SetActive();

protected:
    

private:
    static AbstractWindow* active;
};

}