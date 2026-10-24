#pragma once
#include "Player.h"
#include "Map.h"

class Game
{
private:
	Player player;
	Map map;

	int nowCount;
	int prevCount;

public:
	Game();
	~Game();
	void Init();
	void Run();
	
private:
	void Update(float deltaTime);
	void Draw();
};

