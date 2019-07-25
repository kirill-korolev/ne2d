#ifndef NE_TYPES_H
#define NE_TYPES_H

#include <SDL.h>

namespace ne {

    typedef char          Char;
    typedef unsigned char UChar;
    typedef int           Int;
    typedef unsigned int  UInt;
    typedef Uint8         UInt8;
    typedef long          Long;
    typedef long long     LongLong;
    typedef float         Float;
    typedef bool          Bool;

    typedef void*         VPtr;
    typedef uintptr_t     UIntPtr;
    typedef ptrdiff_t     PtrDiff;

    class Size {
    public:
        Size(Int width, Int height): width(width), height(height){}
    public:
        Int width;
        Int height;
    };
}

#include <string>
#include <unordered_map>
#include <vector>

// For debugging
#include <iostream>

namespace ne {

    //TODO: For now
    using String = std::string;

    //TODO: For now
    template <typename Key, typename Value>
    using Map = std::unordered_map<Key, Value>;

    //TODO: For now
    template <typename T>
    using Array = std::vector<T>;

    template <typename T>
    using InitializerList = std::initializer_list<T>;
}

#endif //NE_TYPES_H
