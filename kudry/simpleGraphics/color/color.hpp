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

    static const Color BlackColor;
    static const Color RedColor;
    static const Color GreenColor;
    static const Color BlueColor;
    static const Color WhiteColor;
    static const Color LightGreyColor;
    static const Color DarkGreyColor;
};
/*
const Color Black(0, 0, 0);
const Color Red(255, 0, 0);
const Color Green(0, 255, 0);
const Color Blue(0, 0, 255);
const Color White(255, 255, 255);
*/
}