#include "Window.h"

int WINAPI WinMain(HINSTANCE hInst, HINSTANCE hPrevInstance, 
				   char* pcCommandLine, int iShowCommand)
{
	Window window;
	window.Init(GetModuleHandle(0), "Test", 800, 600, 500, 500);

	
	return 0;
}