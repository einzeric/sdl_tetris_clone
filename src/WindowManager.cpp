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

void WindowManager::Initialize()
{
    //Initialize SDL system
    if(SDL_Init(SDL_INIT_EVERYTHING) < 0)
    {
        Logger::LOG_E("Failed to initalize SDL.");
        throw SDL_Exception();
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
            Logger::LOG_E("Window creation failed.");
            throw SDL_Exception();
        }
    }
}

std::unique_ptr<SDL_Renderer, decltype(&SDL_DestroyRenderer)> WindowManager::SummonRenderer(int driverIndex, Uint32 renderFlag)
{
    if(!mWindow)
    {
        Logger::LOG_E("Error! Window not initialized!");
        return std::unique_ptr<SDL_Renderer, decltype(&SDL_DestroyRenderer)>(nullptr, SDL_DestroyRenderer);
    }
    Logger::LOG_I("Summoning Diabl... I mean renderer!");
    return std::unique_ptr<SDL_Renderer, decltype(&SDL_DestroyRenderer)>(SDL_CreateRenderer(mWindow.get(), driverIndex, renderFlag), SDL_DestroyRenderer);
}
