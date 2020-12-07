#pragma once
// Just logs, nothing more

#include <string>
#include <sstream>
#include <iostream>
// #include <experimental/source_location>

class Format
{
public:
    Format(const std::string& formatString);

    template<typename T>
    Format& operator,(const T& argument);

    friend std::ostream& operator<<(std::ostream &os, const Format& fmt);

private:
    size_t lastPos;
    std::string formatString;
    std::stringstream formatted;
};

/*-----------------------------------IMPL-----------------------------------*/

template<class T> Format& Format::operator,(const T &argument)
{
    size_t nearestPercent = formatString.find('%', lastPos);
    if (nearestPercent != std::string::npos)
    {
        formatted << formatString.substr(lastPos, nearestPercent - lastPos);
        formatted << argument;
        lastPos = nearestPercent + 1;
    }
    return *this;
}

/*-----------------------------------OTHER---------------------------------*/

#ifdef DEBUG

#define LOGS(...)\
    fprintf(stderr, "-----LOG-----\n~~~~~~~~~~~~~\n");\
    fprintf(stderr, __VA_ARGS__);\
    fprintf(stderr, "\n~~~~~~~~~~~~~\nFILE: %s\nLINE: %d\nFUNC: %s", __FILE__, __LINE__,__func__);\
    fprintf(stderr, "\n---LOG-END---\n\n\n\n");


#else

#define LOGS(...)

#endif