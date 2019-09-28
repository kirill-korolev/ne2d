#include "object.hpp"
#include "game.hpp"
#include "input.hpp"

namespace ne {

    LoaderParams::LoaderParams(Int x, Int y, Int width, Int height, const String& textureId):
        mX(x), mY(y), mW(width), mH(height), mTextureId(textureId){}
    Int LoaderParams::getX() const { return mX; }
    Int LoaderParams::getY() const { return mY; }
    Int LoaderParams::getWidth() const { return mW; }
    Int LoaderParams::getHeight() const { return mH; }
    const String& LoaderParams::getTextureId() const { return mTextureId; }

    SDLGameObject::SDLGameObject(const LoaderParams& loader):
        mPos(loader.getX(), loader.getY()), mVel(), mAcc(),
        mSize(loader.getWidth(), loader.getHeight()), mCurrentRow(1),
        mCurrentFrame(1), mTextureId(loader.getTextureId()){}

    void SDLGameObject::update() {
        mVel += mAcc;
        mPos += mVel;
    }

    void SDLGameObject::draw() {

        if(mVel.x > 0){
            TextureManager::instance().drawFrame(
                    mTextureId, (Int)mPos.x, (Int)mPos.y,
                    mSize.width, mSize.height, mCurrentRow,
                    mCurrentFrame, Game::instance().getRenderer(),
                    SDL_FLIP_HORIZONTAL
            );
        } else {
            TextureManager::instance().drawFrame(
                    mTextureId, (Int)mPos.x, (Int)mPos.y,
                    mSize.width, mSize.height, mCurrentRow,
                    mCurrentFrame, Game::instance().getRenderer()
            );
        }
    }

    void SDLGameObject::clean(){}
}