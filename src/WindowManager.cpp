#include "WindowManager.hpp"

WindowManager::WindowManager() : 
    mWindow(nullptr, SDL_DestroyWindow)
{
    Logger::LOG_I("Creating WindowManager.");
}

WindowManager::~WindowManager()
{
    Logger::LOG_I("Program exiting, releasing resources.");
    Logger::LOG_I("Destroying window.");
    mWindow.reset();
    Logger::LOG_I("Quitting SDL.");
    SDL_Quit();
}

bool WindowManager::Initialize()
{
    //Initialize SDL system
    if(SDL_Init(SDL_INIT_VIDEO) < 0)
    {
        Logger::LOG_E("Failed to initalize SDL with error:");
        Logger::LOG_E(SDL_GetError());
        return FAIL;
    }
    else
    {
        //Create the window
        Logger::LOG_I("Init success, creating window.");
        mWindow = std::unique_ptr<SDL_Window, decltype(&SDL_DestroyWindow)>(SDL_CreateWindow(WINDOW_NAME.c_str(),
                                                                                                SDL_WINDOWPOS_UNDEFINED,
                                                                                                SDL_WINDOWPOS_UNDEFINED,
                                                                                                WINDOW_WIDTH,
                                                                                                WINDOW_HEIGHT,
                                                                                                SDL_WINDOW_SHOWN),
                                                                            SDL_DestroyWindow);
        if(!mWindow)
        {
            Logger::LOG_E("Window creation failed with error:");
            Logger::LOG_E(SDL_GetError());
            return FAIL;
        }
    }
    
    return SUCC;
}
