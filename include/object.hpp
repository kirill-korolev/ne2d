#ifndef NE_OBJECT_H
#define NE_OBJECT_H

#include "texture.hpp"
#include "vector.hpp"

namespace ne {
    class LoaderParams {
    public:
        LoaderParams(Int x, Int y, Int width, Int height, const String& textureId);
        Int getX() const;
        Int getY() const;
        Int getWidth() const;
        Int getHeight() const;
        const String& getTextureId() const;
    private:
        Int mX;
        Int mY;
        Int mW;
        Int mH;
        String mTextureId;
    };

    class GameObject {
    public:
        virtual void update()=0;
        virtual void draw()=0;
        virtual void clean()=0;
        virtual ~GameObject()=default;
    };

    class SDLGameObject: public GameObject {
    public:
        explicit SDLGameObject(const LoaderParams& loader);
        void update() override;
        void draw() override;
        void clean() override;
    protected:
        Vec2 mPos;
        Vec2 mVel;
        Vec2 mAcc;
        Size mSize;
        Int mCurrentRow;
        Int mCurrentFrame;
        String mTextureId;
    };
}

#endif //NE_OBJECT_H
