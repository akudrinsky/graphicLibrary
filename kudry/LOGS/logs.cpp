#include "logs.hpp"

Format::Format(const std::string &formatString)
    :
    lastPos(0),
    formatString(formatString)
{}

std::ostream& operator<<(std::ostream &os, const Format& fmt) {
    os << fmt.formatted.str() << fmt.formatString.substr(fmt.lastPos, fmt.formatString.size() - fmt.lastPos);
    return os;
}