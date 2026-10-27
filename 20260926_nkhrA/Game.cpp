#include "Game.h"
#include "DxLib.h"

Game::Game()
{
	nowCount = 0;
	prevCount = 0;
}

Game::~Game()
{
	DxLib_End();
}

// 
// 初期化
// 

bool Game::Init()
{
	ChangeWindowMode(TRUE);

	SetGraphMode(Config::WINDOW_WIDTH, Config::WINDOW_HEIGHT, Config::COLOR_BIT);
	
	if (DxLib_Init() == -1)
	{
		return false;
	}
	
	// Playerの初期化
	if (!player.Init())
	{
		return false;
	}

	// Mapの初期化
	if (!map.Init())
	{
		return false;
	}

	// タイマーの初期化
	nowCount = GetNowCount();
	prevCount = nowCount;
	return true;
}

// 
// ゲームループ
// 
void Gmae::Run()
{
	while (ProcessMessage() == 0 && !CheckHitKey(KEY_INPUT_ESCAPE)==0)
	{
		// デルタタイム
		nowCount = GetNowCount();
		float deltaTime = (nowCount - prevCount) / 1000.0f;

		// プレイヤーの更新
		player.Update(deltaTime);

		// 描画
		ClearDrawScreen();
		Draw();
		ScreenFlip();
		prevCount = nowCount;
	}
}

// 
// 更新
//
void Game::Update(float deltaTime)
{
	// プレイヤーの更新
	player.Update(deltaTime);
}

// 
// 描画
// 
void Game::Draw()
{
	// マップの描画
	map.Draw();
	// プレイヤーの描画
	player.Draw();
}