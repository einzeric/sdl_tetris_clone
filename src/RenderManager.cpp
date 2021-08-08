#include "RenderManager.hpp"

RenderManager::RenderManager() : 
    mRenderer(nullptr, SDL_DestroyRenderer)
{
}

RenderManager::~RenderManager()
{
}

