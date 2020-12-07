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

template<typename... Args>
void LOGS(std::string formatString, Args... args)
{
    std::cerr << "-----LOG-----\n~~~~~~~~~~~~~\n";
    std::cerr << (Format(formatString), args...);
    //std::cerr << (Format("\n~~~~~~~~~~~~~\nFILE: %\nLINE: %\nFUNC: %"), );
    fprintf(stderr, "\n---LOG-END---\n\n\n\n");
}

#else

template<typename... Args>
void LOGS(std::string formatString, Args... args)
{}

#endif