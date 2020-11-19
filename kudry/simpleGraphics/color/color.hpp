#pragma once

namespace kudry 
{

// Color-describing interface for kudry drawing library
class Color 
{
public:
    Color(int Red, int Green, int Blue);

    int Red;
    int Green;
    int Blue;
};

const Color Black(0, 0, 0);
const Color Red(255, 0, 0);
const Color Green(0, 255, 0);
const Color Blue(0, 0, 255);
const Color White(255, 255, 255);

}