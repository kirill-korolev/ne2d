#include "string.hpp"

namespace ne {
    String joinStrings(const InitializerList<String>& strings, const Char* delim){
        String result;

        for(const auto& string: strings){
            result.append(string);
            result.append(delim);
        }

        return result;
    }
}