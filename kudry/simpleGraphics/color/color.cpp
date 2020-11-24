#include "color.hpp"

namespace kudry 
{

Color::Color(int Red, int Green, int Blue) 
    : 
    Red(Red),
    Green(Green),
    Blue(Blue) 
{}
const kudry::Color kudry::Color::BlackColor(0, 0, 0);
const kudry::Color kudry::Color::RedColor(255, 0, 0);
const kudry::Color kudry::Color::GreenColor(0, 255, 0);
const kudry::Color kudry::Color::BlueColor(0, 0, 255);
const kudry::Color kudry::Color::WhiteColor(255, 255, 255);

}