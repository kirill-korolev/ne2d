#ifndef NE_INPUT_H
#define NE_INPUT_H

#include <SDL.h>
#include "types.hpp"
#include "vector.hpp"

namespace ne {
    class InputHandler {
    public:
        static InputHandler& instance();
        void initializeJoysticks();
        bool joysticksInitialized() const;
        bool isKeyDown(SDL_Scancode key) const;
        Vec2& getMousePos();
        const Vec2& getMousePos() const;
        void update();
        void clean();
        ~InputHandler()=default;
    private:
        InputHandler();
        void onMouseButtonDown(const SDL_Event& event);
        void onMouseButtonUp(const SDL_Event& event);
        void onMouseMove(const SDL_Event& event);
        void onKeyDown();
        void onKeyUp();
    private:
        Vec2 mMousePos;
        bool mMouseButtonState[3];
        const UInt8* mKeyboardState;
        Array<SDL_Joystick*> mJoysticks;
        bool mJoysticksInitialized;
    };
}

#endif //SDL_INPUT_H
