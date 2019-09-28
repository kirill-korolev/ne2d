#ifndef NE_STATE_MACHINE_H
#define NE_STATE_MACHINE_H

#include "state.hpp"

namespace ne {
    class StateMachine {
    public:
        void update();
        void render();
        void pushState(GameState* state);
        void changeState(GameState* state);
        void popState();
    private:
        Array<GameState*> mStates;
    };
}

#endif //NE_STATE_MACHINE_H
