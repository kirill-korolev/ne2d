#include "object_factory.hpp"

namespace ne {
    bool ObjectFactory::registerType(const String& typeId, BaseCreator* creator){
        auto it = mCreators.find(typeId);

        if(it != mCreators.end()){
            delete creator;
            return false;
        }

        mCreators[typeId] = creator;
        return true;
    }

    GameObject* ObjectFactory::create(const String& typeId){
        auto it = mCreators.find(typeId);

        if(it == mCreators.end())
            return nullptr;

        return it->second->createObject();
    }
}
