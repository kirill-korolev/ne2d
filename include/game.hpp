#ifndef NE_GAME_H
#define NE_GAME_H

#include <SDL.h>
#include "types.hpp"
#include "state_machine.hpp"
#include "exception.hpp"

namespace ne {

    class GameObject;
    class Player;

    class Game {
    public:
        static Game& instance();

        template <typename InitFunction>
        void init(const Char* title, Int x, Int y, Int width, Int height, Int flags, InitFunction init){
            SDL_ASSERT(SDL_Init(SDL_INIT_EVERYTHING) >= 0);
            mWindow = SDL_CreateWindow(title, x, y, width, height, flags);
            SDL_ASSERT(mWindow);
            mRenderer = SDL_CreateRenderer(mWindow, -1, 0);
            SDL_ASSERT(mRenderer);
            SDL_SetRenderDrawColor(mRenderer, 0, 0, 0, 255);
            init(mStateMachine);
            mRunning = true;
        }

        void update();
        void render();
        SDL_Renderer* getRenderer();
        const SDL_Renderer* getRenderer() const;
        StateMachine& getState();
        const StateMachine& getState() const;
        bool running() const;
        void handleEvents();
        void clean();
        void quit();
        virtual ~Game();
    private:
        Game();
    private:
        SDL_Window* mWindow;
        SDL_Renderer* mRenderer;
        StateMachine mStateMachine;
        bool mRunning;
    };
}

#endif //NE_GAME_H