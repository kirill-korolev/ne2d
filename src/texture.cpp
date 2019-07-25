#include <SDL_image.h>
#include "texture.hpp"
#include "exception.hpp"

namespace ne {

    TextureManager& TextureManager::instance(){
        static TextureManager manager;
        return manager;
    }

    void TextureManager::load(const String& filename, const String& id, SDL_Renderer* renderer){
        SDL_ASSERT_MESSAGE(renderer, "Texture manager cannot operate with nil renderer");
        SDL_Surface* surf = IMG_Load(filename.c_str());
        SDL_ASSERT(surf);
        SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, surf);
        SDL_ASSERT(texture);
        mTextures[id] = texture;
        SDL_FreeSurface(surf);
    }

    void TextureManager::draw(const String& id, Int x, Int y, Int width, Int height,
                              SDL_Renderer* renderer, SDL_RendererFlip flip){
        SDL_ASSERT_MESSAGE(renderer, "Texture manager cannot operate with nil renderer");
        SDL_ASSERT_MESSAGE(mTextures.find(id) != mTextures.end(), "Unknown texture ID");
        SDL_Rect srcRect{}, dstRect{};
        srcRect.w = dstRect.w = width;
        srcRect.h = dstRect.h = height;
        dstRect.x = x;
        dstRect.y = y;
        SDL_RenderCopyEx(renderer, mTextures[id], &srcRect, &dstRect, 0, nullptr, flip);
    }

    void TextureManager::drawFrame(const String& id, Int x, Int y, Int width, Int height,
                                   Int currentRow, Int currentFrame, SDL_Renderer* renderer,
                                   SDL_RendererFlip flip){
        SDL_ASSERT_MESSAGE(renderer, "Texture manager cannot operate with nil renderer");
        SDL_ASSERT_MESSAGE(mTextures.find(id) != mTextures.end(), "Unknown texture ID");
        SDL_Rect srcRect{}, dstRect{};
        srcRect.x = width * currentFrame;
        srcRect.y = height * (currentRow - 1);
        srcRect.w = dstRect.w = width;
        srcRect.h = dstRect.h = height;
        dstRect.x = x;
        dstRect.y = y;
        SDL_RenderCopyEx(renderer, mTextures[id], &srcRect, &dstRect, 0, nullptr, flip);
    }

    void TextureManager::clearFromTextureMap(const String& id){
        mTextures.erase(id);
    }

}