#pragma once
//STL include
#include <memory>
//SDL include
#include <SDL2/SDL.h>
//Project specific include
#include "Logger.hpp"

class RenderManager
{
public:
    RenderManager();
    ~RenderManager();
    
    void setRenderer(std::unique_ptr<SDL_Renderer, decltype(&SDL_DestroyRenderer)> renderer);

    //Public constants (so I don't have to implement getters for 'em, that's just plain stupid)
    const int driverIndex = -1;
    const Uint32 renderFlag = SDL_RENDERER_ACCELERATED;
private:
    std::unique_ptr<SDL_Renderer, decltype(&SDL_DestroyRenderer)> mRenderer;
};

