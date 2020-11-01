

namespace kudry
{

class Font 
{
public:
    Font(const char* pathToFont);

    static void MakeDefault(const Font& newDefault);

    static const Font& Default();

    

private:
    static Font* defaultFont;

};

}