#pragma once
//SDL include
#include <SDL2/SDL.h>
//STD lib include
#include <memory>
#include <string>
//Project specific include
#include "Logger.hpp"

class WindowManager
{
public:
    WindowManager();
    ~WindowManager();
    bool Initialize();
    
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

