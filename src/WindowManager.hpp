#pragma once
//SDL include
#include <SDL2/SDL.h>
//STD lib include
#include <memory>
#include <string>
//Project specific include
#include "Logger.hpp"
#include "SDL_Exception.hpp"

class WindowManager
{
public:
    WindowManager();
    ~WindowManager();
    void Initialize();
    std::unique_ptr<SDL_Renderer, decltype(&SDL_DestroyRenderer)> SummonRenderer();
    
private:
    //Constants
    const bool FAIL = false;
    const bool SUCC = true;
    const std::string WINDOW_NAME = "Tetris";
    const int WINDOW_WIDTH = 800;    
    const int WINDOW_HEIGHT = 800;    
    
    //Class data
    std::unique_ptr<SDL_Window, decltype(&SDL_DestroyWindow)> mWindow;
};

