//
// Created by baifeng on 2021/7/12.
//

#ifndef SDL2_TEST_GAME_H
#define SDL2_TEST_GAME_H

#include "common/game.h"
#include "common/loadres.h"
#include "common/render.h"

#define SCREEN_WIDTH 480
#define SCREEN_HEIGHT 272

class MyApp : public Game::App {
private:
    SDL_Texture* bg;
    RenderCopy bg_render;

    SDL_Texture* icon;
    RenderCopyEx icon_render_1;
    RenderCopyEx icon_render_2;

public:
    void init() override {
        auto renderer = _game.renderer();

        bg = res::load_texture(renderer, "assets/bg.jpg");
        bg_render.setTexture(bg);
        bg_render.setSize(SCREEN_WIDTH, SCREEN_HEIGHT);

        icon = res::load_texture(renderer, "assets/1.png");
        icon_render_1.setTexture(icon);
        //arrow_render.setAnchor({0.5f, 1.0f});
        icon_render_1.setPosition(SCREEN_WIDTH * 0.25f, SCREEN_HEIGHT * 0.5f);
        icon_render_1.setAngle(90);

        icon_render_2.setTexture(icon);
        //tileset_render.setScale({1.3f, 1.3f});
        icon_render_2.setPosition(SCREEN_WIDTH * 0.75f, SCREEN_HEIGHT * 0.5f);
        icon_render_2.setAnchor({0.0f, 0.5f});
        icon_render_2.setAngle(90);
    }
    void update(float dt) override {
        auto angle = icon_render_1.getAngle();
        icon_render_1.setAngle(angle += 90 * dt);
        angle = icon_render_2.getAngle();
        icon_render_2.setAngle(angle -= 90 * dt);
    }
    void render(SDL_Renderer* renderer) override {
        bg_render.draw(renderer);
        icon_render_2.draw(renderer);
        icon_render_1.draw(renderer);
    }
    void fini() override {
        res::free_texture(bg);
        res::free_texture(icon);
    }
    Vector2i screenSize() override {
        return {SCREEN_WIDTH, SCREEN_HEIGHT};
    }
};

#endif //SDL2_TEST_GAME_H
