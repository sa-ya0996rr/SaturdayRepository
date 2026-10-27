#include "Game.h"
#include "DxLib.h"

int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int)
{
	Game game;
	
	if (!game.Init())
	{
		return -1;
	}
	
	game.Run();
	
	return 0;
}