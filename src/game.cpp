#include "game.hpp"
#include "exception.hpp"
#include "input.hpp"

namespace ne {
    Game& Game::instance() {
        static Game game;
        return game;
    }

    Game::Game(): mWindow(nullptr), mRenderer(nullptr), mRunning(false){}

    void Game::update(){
        mStateMachine.update();
    }

    void Game::render(){
        SDL_RenderClear(mRenderer);
        mStateMachine.render();
        SDL_RenderPresent(mRenderer);
    }

    SDL_Renderer* Game::getRenderer() { return mRenderer; }
    const SDL_Renderer* Game::getRenderer() const { return mRenderer; }

    StateMachine& Game::getState() { return mStateMachine; }
    const StateMachine& Game::getState() const { return mStateMachine; }

    bool Game::running() const { return mRunning; }

    void Game::handleEvents(){
        InputHandler::instance().update();
    }

    void Game::clean(){
        InputHandler::instance().clean();
        SDL_DestroyRenderer(mRenderer);
        SDL_DestroyWindow(mWindow);
        SDL_Quit();
    }

    void Game::quit(){
        mRunning = false;
    }

    Game::~Game(){ clean(); }
}
