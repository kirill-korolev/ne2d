#include <iostream>

#include "game.hpp"

using namespace ne;

namespace ne {
    class Player: public SDLGameObject {
    public:
        explicit Player(const LoaderParams& loader);
        void handleInput();
        void update() override;
    };

    class Enemy: public SDLGameObject {
    public:
        explicit Enemy(const LoaderParams& loader);
        void update() override;
    };

    Player::Player(const LoaderParams& loader): SDLGameObject(loader){}

    void Player::handleInput(){
        Vec2& mousePos = InputHandler::instance().getMousePos();
        mVel = mousePos - mPos;
        mVel /= 50;
    }

    void Player::update() {
        mVel = Vec2();
        handleInput();
        mCurrentFrame = Int((SDL_GetTicks() / 100) % 5);
        SDLGameObject::update();
    }

    Enemy::Enemy(const LoaderParams& loader): SDLGameObject(loader){}

    void Enemy::update(){
        mVel = Vec2();
        mCurrentFrame = Int((SDL_GetTicks() / 100) % 5);
        SDLGameObject::update();
    }

    class PlayState: public GameState {
    public:
        void update() override;
        void render() override;
        void onEnter() override;
        void onExit() override;
        const String& getStateId() const override;
    private:
        Array<GameObject*> mObjects;
        static const String sPlayStateId;
    };

    const String PlayState::sPlayStateId = "PLAY";

    void PlayState::update() {
        for(auto& obj: mObjects)
            obj->update();
    }

    void PlayState::render() {
        for(auto& obj: mObjects)
            obj->draw();
    }

    void PlayState::onEnter() {
        TextureManager::instance().load("assets/helicopter.png", "helicopter", Game::instance().getRenderer());
        TextureManager::instance().load("assets/helicopter2.png", "helicopter2", Game::instance().getRenderer());

        GameObject* player = new Player(LoaderParams(100, 100, 128, 55, "helicopter"));
        GameObject* enemy = new Enemy(LoaderParams(500, 100, 128, 55, "helicopter2"));

        mObjects.push_back(player);
        mObjects.push_back(enemy);
    }

    void PlayState::onExit() {
        for(auto& obj: mObjects)
            obj->clean();
        mObjects.clear();
    }

    const String& PlayState::getStateId() const { return sPlayStateId; }
}

int main() {

    try {

        Game::instance().init("Game", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 640, 480, 0,
        [](StateMachine* sm){
            sm->pushState(new PlayState);
        });

        const int FPS = 60;
        const float DELAY_TIME = 1000.0f / FPS;

        Uint32 frameStart, frameTime;

        while(true){
            frameStart = SDL_GetTicks();

            Game::instance().handleEvents();

            if(!Game::instance().running())
                break;

            Game::instance().update();
            Game::instance().render();

            frameTime = SDL_GetTicks() - frameStart;

            if(frameTime < DELAY_TIME){
                SDL_Delay((int)(DELAY_TIME - frameTime));
            }
        }
    } catch(const ne::Exception& e){
        std::cerr << e.what() << std::endl;
        return -1;
    }

    return 0;
}