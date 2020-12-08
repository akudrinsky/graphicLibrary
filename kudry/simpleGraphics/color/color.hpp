#pragma once

#include <cstdlib>

namespace kudry 
{

// Type that describes thickness of lines
typedef int Thickness_t;

// Color-describing interface for kudry drawing library
class Color 
{
public:
    Color(uint8_t Red, uint8_t Green, uint8_t Blue, uint8_t Alpha = 255);

    Color(const Color& clr);

    uint8_t Red;
    uint8_t Green;
    uint8_t Blue;
    uint8_t Alpha;

    static const Color BlackColor;
    static const Color RedColor;
    static const Color GreenColor;
    static const Color BlueColor;
    static const Color WhiteColor;
    static const Color LightGreyColor;
    static const Color DarkGreyColor;
};

}