#include "color.hpp"

namespace kudry 
{

Color::Color(int Red, int Green, int Blue) 
    : 
    Red(Red),
    Green(Green),
    Blue(Blue) 
{}
const Color Color::BlackColor(0, 0, 0);
const Color Color::RedColor(255, 0, 0);
const Color Color::GreenColor(0, 255, 0);
const Color Color::BlueColor(0, 0, 255);
const Color Color::WhiteColor(255, 255, 255);
const Color Color::LightGreyColor(200, 200, 200);
const Color Color::DarkGreyColor(100, 100, 100);

}