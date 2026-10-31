#include "Game.h"
#include "Config.h"
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

// ==========================
// 初期化
// ==========================
bool Game::Init()
{
	ChangeWindowMode(TRUE);

	SetGraphMode(Config::WINDOW_WIDTH, Config::WINDOW_HEIGHT, Config::COLOR_BIT);

	if (DxLib_Init() == -1)
	{
		return false;
	}

	// プレイヤーの初期化
	if (!player.Init())
	{
		return false;
	}

	// マップの初期化
	if (!map.Init())
	{
		return false;
	}

	// タイマーの初期化
	nowCount = GetNowCount();
	prevCount = nowCount;
	return true;
}

// ==========================
// ゲームループ
// ==========================
void Game::Run()
{
	while (ProcessMessage() == 0 && CheckHitKey(KEY_INPUT_ESCAPE) == 0)
	{
		// デルタタイム
		nowCount = GetNowCount();

		float deltaTime = (nowCount - prevCount) / 1000.0f;

		// フレーム
		if (deltaTime > 0.05f)
		{
			deltaTime = 0.05f;
		}

		// 更新
		Update(deltaTime);

		// 描画
		ClearDrawScreen();
		Draw();
		ScreenFlip();
		prevCount = nowCount;
	}
}

// ==========================
// 更新
//==========================
void Game::Update(float deltaTime)
{
	// プレイヤーの更新
	player.Update(deltaTime, map);
}

// ==========================
// 描画
// ==========================
void Game::Draw()
{
	// マップの描画
	map.Draw();
	// プレイヤーの描画
	player.Draw();
}