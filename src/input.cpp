#include "input.hpp"
#include "exception.hpp"
#include "game.hpp"

namespace ne {
    InputHandler& InputHandler::instance(){
        static InputHandler handler;
        return handler;
    }

    InputHandler::InputHandler():
        mJoysticksInitialized(false), mKeyboardState(nullptr), mMouseButtonState{false}, mMousePos() {}

    void InputHandler::initializeJoysticks(){
        if(SDL_WasInit(SDL_INIT_JOYSTICK) == 0)
            SDL_InitSubSystem(SDL_INIT_JOYSTICK);

        if(SDL_NumJoysticks() > 0){
            for(Int i = 0; i < SDL_NumJoysticks(); ++i){
                SDL_Joystick* joy = SDL_JoystickOpen(i);
                SDL_ASSERT(joy);
                mJoysticks.push_back(joy);
            }
            SDL_JoystickEventState(SDL_ENABLE);
            mJoysticksInitialized = true;
        }
    }

    bool InputHandler::joysticksInitialized() const { return mJoysticksInitialized; }

    void InputHandler::update(){
        SDL_Event event{};
        if(SDL_PollEvent(&event)){
            switch(event.type){
                case SDL_QUIT:
                    Game::instance().quit();
                    break;
                case SDL_MOUSEBUTTONDOWN:
                    onMouseButtonDown(event);
                    break;
                case SDL_MOUSEBUTTONUP:
                    onMouseButtonUp(event);
                    break;
                case SDL_MOUSEMOTION:
                    onMouseMove(event);
                    break;
                case SDL_KEYDOWN:
                    onKeyDown();
                    break;
                case SDL_KEYUP:
                    onKeyUp();
                    break;
                default:
                    break;
            }
        }
    }

    void InputHandler::onKeyDown(){
        mKeyboardState = SDL_GetKeyboardState(nullptr);
    }

    void InputHandler::onKeyUp(){
        mKeyboardState = SDL_GetKeyboardState(nullptr);
    }

    bool InputHandler::isKeyDown(SDL_Scancode key) const {
        if(!mKeyboardState)
            return false;
        return mKeyboardState[key];
    }

    Vec2& InputHandler::getMousePos() { return mMousePos; }

    const Vec2& InputHandler::getMousePos() const { return mMousePos; }

    void InputHandler::onMouseButtonDown(const SDL_Event& event){
        if(event.button.button >= 0 && event.button.button <= 2)
            mMouseButtonState[event.button.button - 1] = true;
    }

    void InputHandler::onMouseButtonUp(const SDL_Event& event){
        if(event.button.button >= 0 && event.button.button <= 2)
            mMouseButtonState[event.button.button - 1] = false;
    }

    void InputHandler::onMouseMove(const SDL_Event& event){
        mMousePos.x = event.motion.x;
        mMousePos.y = event.motion.y;
    }

    void InputHandler::clean() {
        delete mKeyboardState;

        if(mJoysticksInitialized){
            for(Int i = 0; i < SDL_NumJoysticks(); ++i){
                SDL_JoystickClose(mJoysticks[i]);
            }
        }
    }
}