#ifndef NE_OBJECT_FACTORY_H
#define NE_OBJECT_FACTORY_H

#include "object.hpp"

namespace ne {

    class BaseCreator {
    public:
        virtual GameObject* createObject()=0;
        virtual ~BaseCreator()=default;
    };

    class ObjectFactory {
    public:
        bool registerType(const String& typeId, BaseCreator* creator);
        GameObject* create(const String& typeId);
    private:
        Map<String, BaseCreator*> mCreators;
    };
}

#endif //NE_OBJECT_FACTORY_H
