#include "Sprite/Sprite.hpp"

Sprite::Sprite(float x, float y, float width, float height)
{
  this->setPosition(x, y);
  this->setSize(width, height);

  this->_texture_transform.x = 0;
  this->_texture_transform.y = 0;
}

void Sprite::setSize(float width, float height) noexcept
{
  this->_sprite_transform.w = width;
  this->_sprite_transform.h = height;
}
void Sprite::setPosition(float x, float y) noexcept
{
  this->_sprite_transform.x = x;
  this->_sprite_transform.y = y;
}
const SDL_Rect &Sprite::getTextureTransform() const noexcept
{
  return this->_texture_transform;
}
const SDL_FRect &Sprite::getTransform() const noexcept
{
  return this->_sprite_transform;
}
void Sprite::setTexture(SDL_Texture *texture) noexcept
{
  this->_texture = texture;
  SDL_QueryTexture(this->_texture, NULL, NULL, &this->_texture_transform.w, &this->_texture_transform.h);
}
void Sprite::render(SDL_Renderer *renderer) noexcept
{
  SDL_RenderCopyF(renderer, this->_texture, &this->_texture_transform, &this->_sprite_transform);
}
void Sprite::setTextureTransform(SDL_Rect texture_treansform) noexcept
{
  this->_texture_transform = texture_treansform;
}
void Sprite::move(float x, float y) noexcept
{
  this->_sprite_transform.x += x;
  this->_sprite_transform.y += y;
}

Sprite::~Sprite()
{
}
