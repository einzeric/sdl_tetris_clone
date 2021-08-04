#include <WindowManager.hpp>

int main(int argc, char* args[])
{
    WindowManager iWindowManager;
    if(!iWindowManager.Initialize())
    {
        Logger::LOG_E("Failed to start game");
    }
    else
    {
        Logger::LOG_I("Game running.");
    }
	return 0;
}
