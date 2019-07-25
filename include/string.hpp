#ifndef NE_STRING_H
#define NE_STRING_H

#include "types.hpp"

namespace ne {
    String joinStrings(const InitializerList<String>& strings, const Char* delim=" ");
}

#endif //NE_STRING_H
