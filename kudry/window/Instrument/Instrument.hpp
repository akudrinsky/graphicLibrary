#include "../AbstractWindow.hpp"

namespace kudry
{

class Instrument : AbstractWindow
{
public:

    void SetActive();

protected:
    static AbstractWindow* active;
};

}