#include "state_machine.hpp"

namespace ne {

    void StateMachine::update(){
        if(!mStates.empty())
            mStates.back()->update();
    }

    void StateMachine::render(){
        if(!mStates.empty())
            mStates.back()->render();
    }

    void StateMachine::pushState(GameState* state){
        mStates.push_back(state);
        mStates.back()->onEnter();
    }

    void StateMachine::changeState(GameState* state){
        if(!mStates.empty() && mStates.back()->getStateId() == state->getStateId())
            return;
        popState();
        pushState(state);
    }

    void StateMachine::popState(){
        if(!mStates.empty()){
            mStates.back()->onExit();
            delete mStates.back();
            mStates.pop_back();
        }
    }

}