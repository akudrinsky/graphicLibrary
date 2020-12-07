#include "../kudry/Application/Application.hpp"
#include "../kudry/engine/SFML/engineSFML.hpp"
#include "../kudry/window/Scrollbar/ScrollableText.hpp"
#include "../kudry/LOGS/logs.hpp"

#include <fstream>
#include <string>
#include <streambuf>
#include <sstream>

int main(int argc, char* argv[]) 
{
    if (argc != 2) 
    {
        printf("Need name if window\n");
        exit(1);
    }

    auto& app = 
        kudry::Application<kudry::engineSFML>::GetInstance(argv[1]);

    kudry::Scrollbar scrlbar(
        kudry::FlatObj<int>(1000, 200),
        kudry::FlatObj<int>(30, 700),
        kudry::Color(50, 50, 50),
        kudry::Color(150, 150, 150)
    );

    app.NewWindow(&scrlbar);

    kudry::Font font(
        "/Users/alexeykudrinsky/Documents"
        "/MIPT/2_course/c++/files-dialog/"
        "data/Madina.ttf"
    );
    std::ifstream t("data/BestPoemEver.txt");
    std::stringstream buffer;
    buffer << t.rdbuf();

    kudry::TextWindow text(&font, buffer.str(), 40);

    kudry::ScrollableText scrltext(
        text,
        kudry::FlatObj<int>(100, 100),
        kudry::FlatObj<int>(800, 700),
        kudry::Color(100, 100, 100)
    ); 

    scrltext.Attach(&scrlbar);

    app.NewWindow(&scrltext);

    //app.NewWindow(&text);

    LOGS("loop\n")

    return app.Loop();
}