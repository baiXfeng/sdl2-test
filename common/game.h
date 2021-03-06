//
// Created by baifeng on 2021/6/28.
//

#ifndef MGS_GAME_H
#define MGS_GAME_H

#include <string>
#include <SDL.h>
#include "types.h"

#define GAME_SCREEN_WIDTH 960
#define GAME_SCREEN_HEIGHT 544

class Game {
public:
    class Delegate {
        friend class Game;
    public:
        virtual void init() = 0;
        virtual void fini() = 0;
        virtual void update(float delta) = 0;
        virtual void render(SDL_Renderer* renderer) = 0;
        virtual std::string windowTitle() = 0;
        virtual Vector2i screenSize() = 0;
    };
    class App : public Game::Delegate {
    public:
        App();
        int run();
    protected:
        std::string windowTitle() override {
            return "my_game";
        }
        Vector2i screenSize() override {
            return {GAME_SCREEN_WIDTH, GAME_SCREEN_HEIGHT};
        }
        void init() override {}
        void fini() override {}
        void update(float delta) override {}
        void render(SDL_Renderer* renderer) override {}
    };
public:
    static Game& instance();
    SDL_Renderer* renderer() const;
    void setDelegate(Delegate* p);
    int run();
private:
    Game():_delegate(nullptr) {}
    void input();
private:
    Delegate* _delegate;
};

#define _game Game::instance()

#endif //MGS_GAME_H
