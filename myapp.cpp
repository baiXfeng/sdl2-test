//
// Created by baifeng on 2021/7/12.
//
#include "common/game.h"
#include "common/loadres.h"
#include "common/render.h"

#define SCREEN_WIDTH 960
#define SCREEN_HEIGHT 544

class MyApp : public Game::App {
private:
    SDL_Texture* bg;
    RenderCopy bg_render;

    SDL_Texture* icon;
    RenderCopyEx icon_render_1;
    RenderCopyEx icon_render_2;

    SDL_Texture* render_target;
    RenderCopyEx render_target_copy;

public:
    void init() override {
        auto renderer = _game.renderer();

        bg = res::load_texture(renderer, "assets/bg.jpg");
        bg_render.setTexture(bg);
        bg_render.setSize(SCREEN_WIDTH, SCREEN_HEIGHT);

        icon = res::load_texture(renderer, "assets/1.png");
        icon_render_1.setTexture(icon);
        icon_render_1.setPosition(SCREEN_WIDTH * 0.25f, SCREEN_HEIGHT * 0.5f);
        //icon_render_1.setAnchor({0.5f, 1.0f});

        icon_render_2.setTexture(icon);
        icon_render_2.setScale({1.3f, 1.3f});
        icon_render_2.setPosition(SCREEN_WIDTH * 0.75f, SCREEN_HEIGHT * 0.5f);
        icon_render_2.setAnchor({0.0f, 0.5f});

        render_target = SDL_CreateTexture(renderer, SDL_PIXELFORMAT_RGB888, SDL_TEXTUREACCESS_TARGET, SCREEN_WIDTH, SCREEN_HEIGHT);
        SDL_SetTextureBlendMode(render_target, SDL_BLENDMODE_BLEND);
        render_target_copy.setTexture(render_target);
        render_target_copy.setAnchor({0.5f, 0.5f});
        render_target_copy.setPosition(SCREEN_WIDTH * 0.5f, SCREEN_HEIGHT * 0.5f);
    }
    void update(float dt) override {
        auto angle = icon_render_1.getAngle();
        icon_render_1.setAngle(angle += 90 * dt);
        angle = icon_render_2.getAngle();
        icon_render_2.setAngle(angle -= 90 * dt);

        render_target_copy.setAngle(render_target_copy.getAngle() + 90 * dt);
    }
    void render(SDL_Renderer* renderer) override {

        SDL_SetRenderTarget(renderer, render_target);
        bg_render.draw(renderer);
        icon_render_2.draw(renderer);
        icon_render_1.draw(renderer);
        SDL_SetRenderTarget(renderer, nullptr);

        render_target_copy.draw(renderer);
    }
    void fini() override {
        res::free_texture(bg);
        res::free_texture(icon);
        res::free_texture(render_target);
    }
    Vector2i screenSize() override {
        return {SCREEN_WIDTH, SCREEN_HEIGHT};
    }
};

#if defined(__PSP__)
#include <SDL_main.h>
int SDL_main(int argc, char * argv[]) {
#else
int main(int argc, char * argv[]) {
#endif
    MyApp app;
    return app.run();
}
