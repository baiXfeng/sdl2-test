//
// Created by baifeng on 2021/7/12.
//

#ifndef SDL2_TEST_LOADRES_H
#define SDL2_TEST_LOADRES_H

#include <SDL.h>
#include <SDL_image.h>

namespace res {
    static std::string const& getAssetsPath() {
        static std::string assets_path;
#if defined(__vita__)
        if (assets_path.empty()) {
            assets_path = "app0:";
        }
#endif
        return assets_path;
    }
    static SDL_Texture* load_texture(SDL_Renderer *renderer, std::string const& fileName) {
        return IMG_LoadTexture(renderer, (getAssetsPath()+fileName).c_str());
    }
    static void free_texture(SDL_Texture* texture) {
        SDL_DestroyTexture(texture);
    }
};

#endif //SDL2_TEST_LOADRES_H
