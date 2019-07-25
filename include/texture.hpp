#ifndef NE_TEXTURE_H
#define NE_TEXTURE_H

#include <SDL.h>
#include "types.hpp"

namespace ne {
    class TextureManager {
    public:
        static TextureManager& instance();
        void load(const String& filename, const String& id, SDL_Renderer* renderer);
        void draw(const String& id, Int x, Int y, Int width, Int height,
                  SDL_Renderer* renderer, SDL_RendererFlip flip=SDL_FLIP_NONE);
        void drawFrame(const String& id, Int x, Int y, Int width, Int height,
                       Int currentRow, Int currentFrame, SDL_Renderer* renderer,
                       SDL_RendererFlip flip=SDL_FLIP_NONE);
        void clearFromTextureMap(const String& id);
    private:
        TextureManager()=default;
    private:
        Map<String, SDL_Texture*> mTextures;
    };
}

#endif //NE_TEXTURE_H
