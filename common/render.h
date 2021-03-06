//
// Created by baifeng on 2021/7/12.
//

#ifndef SDL2_TEST_RENDER_H
#define SDL2_TEST_RENDER_H

#include <SDL.h>
#include "types.h"

class RenderCopy {
public:
    RenderCopy();
    virtual ~RenderCopy() {}
public:
    void setTexture(SDL_Texture* texture);
    void setTexture(SDL_Texture* texture, SDL_Rect const& srcrect);
    void setPosition(int x, int y);
    void setSize(int w, int h);
    Vector2i const& position() const;
    Vector2i const& size() const;
public:
    virtual void draw(SDL_Renderer* renderer);
protected:
    SDL_Texture* _texture;
    SDL_Rect _srcrect;
    Vector2i _position;
    Vector2i _size;
};

class RenderCopyEx : public RenderCopy {
public:
    RenderCopyEx();
public:
    void setScale(Vector2f const& scale);
    Vector2f const& getScale() const;
    void setAnchor(Vector2f const& anchor);
    Vector2f const& getAnchor() const;
    void setAngle(float angle);
    float getAngle() const;
public:
    void draw(SDL_Renderer* renderer) override;
protected:
    float _angle;
    Vector2f _scale;
    Vector2f _anchor;
};

#endif //SDL2_TEST_RENDER_H
