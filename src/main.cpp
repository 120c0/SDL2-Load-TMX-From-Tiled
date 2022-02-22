#include <iostream>

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include <tinyxml2.h>
#include <vector>
#include <string>

#include "Sprite/Sprite.hpp"

int main(int, char const*[])
{
  SDL_Window *window = SDL_CreateWindow("PlataformGame", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 500, 500, SDL_WINDOW_SHOWN);
  SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_PRESENTVSYNC | SDL_RENDERER_ACCELERATED);
  SDL_Event event;

  bool is_running = window && renderer;
  std::vector<Sprite> tiles;

  tinyxml2::XMLDocument file_map;
  file_map.LoadFile("data/map/world_1.tmx");

  tinyxml2::XMLElement 
    *root = file_map.FirstChildElement("map"),
    *layer_node = root->FirstChildElement("layer");
  
  SDL_Texture *tileset = IMG_LoadTexture(renderer, "data/assets/DirtBrick_Assets_V5.png");

  while(layer_node)
  {
    std::string number;
    const char *data = layer_node->FirstChildElement("data")->GetText();
    int x = 0, y = 0, map_width = layer_node->IntAttribute("width");
    for(int i = 0; data[i]; i++)
    {
      if(data[i] == ',' || i == (int) strlen(data) - 1)
      {
        int id = atoi(number.data());

        if(id != 0)
        {
          id--;
          tiles.push_back(Sprite(27.f * x, 27.f * y, 27.f, 27.f));
          tiles.back().setTexture(tileset);
          tiles.back().setTextureTransform({id % 20 * 16, (int) std::floor(id / 20) * 16, 16, 16});
        }

        number.clear();
        if(++x == map_width)
        {
          x = 0; y++;
        }
      }
      else
      {
        number += data[i];
      }
      
    }
    layer_node = layer_node->NextSiblingElement();
  }
  std::cout << tiles.size();
  while(is_running)
  {
    while(SDL_PollEvent(&event))
    {
      if(event.type == SDL_QUIT)
      {
        is_running = false;
      }
    }
    SDL_SetRenderDrawColor(renderer, 118, 215, 234, 255);
    SDL_RenderClear(renderer);

    for(auto &tile : tiles)
    {
      if(tile.getTransform().x <= 500 && tile.getTransform().x >= -27)
        tile.render(renderer);
      tile.move(-3.f, 0.f);
    }

    SDL_RenderPresent(renderer);
  }

  return EXIT_SUCCESS;
}