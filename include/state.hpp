#ifndef NE_STATE_H
#define NE_STATE_H

#include "types.hpp"
#include "object.hpp"

namespace ne {
    class GameState {
    public:
        virtual void update()=0;
        virtual void render()=0;
        virtual void onEnter()=0;
        virtual void onExit()=0;
        virtual ~GameState()=default;
        virtual const String& getStateId() const=0;
    };
}

#endif //NE_STATE_H
