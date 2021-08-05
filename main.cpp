#include <WindowManager.hpp>

int main(int argc, char* args[])
{
    WindowManager iWindowManager;
    try
    {
        iWindowManager.Initialize();
    }
    catch(SDL_Exception& e)
    {
        Logger::LOG_E("Exception in program:");
        Logger::LOG_E(e.what());
    }
	return 0;
}
