#ifndef SPRITE_HPP
#define SPRITE_HPP

#include <SDL2/SDL.h>

class Sprite
{
  public:
    explicit Sprite(float, float, float, float);

    virtual void setSize(float, float) noexcept;
    virtual void setPosition(float, float) noexcept;
    const SDL_Rect &getTextureTransform() const noexcept;
    const SDL_FRect &getTransform() const noexcept;
    virtual void setTexture(SDL_Texture*) noexcept;
    virtual void render(SDL_Renderer*) noexcept;
    virtual void setTextureTransform(SDL_Rect) noexcept;
    virtual void move(float, float) noexcept;

    virtual ~Sprite();
  private:
    SDL_FRect _sprite_transform;
    SDL_Rect _texture_transform;
    SDL_Texture *_texture;
};

#endif