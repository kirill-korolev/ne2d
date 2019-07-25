#ifndef SDL_EXCEPTION_H
#define SDL_EXCEPTION_H

#include <SDL.h>
#include "string.hpp"

namespace ne {
    class Exception: public std::exception {
    public:
        explicit Exception(const String& message): mMessage(message){}
        explicit Exception(const Char* message=""): Exception(String(message)){}
        const Char* what() const noexcept override { return mMessage.c_str(); }
    private:
        String mMessage;
    };

    class SDLException: public Exception {
    public:
        SDLException(): Exception(joinStrings({sSDLPrefix, SDL_GetError()})){}
        explicit SDLException(const String& message): Exception(joinStrings({sSDLPrefix, message})){}
        explicit SDLException(const Char* message): SDLException(String(message)){}
    private:
        static constexpr const Char* sSDLPrefix = "SDL:";
    };

}

#define SDL_ASSERT(cond) if(!(cond)) throw SDLException()
#define SDL_ASSERT_MESSAGE(cond, mes) if(!(cond)) throw SDLException((mes))


#endif //SDL_EXCEPTION_H