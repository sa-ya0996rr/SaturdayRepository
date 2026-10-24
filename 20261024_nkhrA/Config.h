#pragma once
namespace Config
{
	// ==========================
	// Window
	// ==========================
	constexpr int WINDOW_WIDTH = 1440;	// ウィンドウ幅
	constexpr int WINDOW_HEIGHT = 900;	// ウィンドウ高さ
	constexpr int COLOR_BIT = 16;		// 色深度

	// ==========================
	// MAP
	//==========================
	constexpr int MAP_CHIP_SIZE = 64;	// マップチップのサイズ

	constexpr int MAP_X_NUM = 16;	// マップの横方向のチップ数
	constexpr int MAP_Y_NUM = 12;	// マップの縦方向のチップ数

	// Map image
	constexpr int MAP_IMG_X_NUM = 2;	// マップ画像の横方向のチップ数
	constexpr int MAP_IMG_Y_NUM = 1;	// マップ画像の縦方向のチップ数

	constexpr const char* MAP_IMG_PATH = "img/map.png";	// マップ画像のパス

	// ==========================
	// Player
	// ==========================
	constexpr float PLAYER_START_X = 100.0f;	// プレイヤーの初期X座標
	constexpr float PLAYER_START_Y = 100.0f;	// プレイヤーの初期Y座標
	constexpr float PLAYER_MOVE_SPEED = 200.0f;	// プレイヤーの移動速度

	// Player image size
	constexpr int PLAYER_IMG_SIZE_X = 64;	// プレイヤー画像の横幅
	constexpr int PLAYER_IMG_SIZE_Y = 96;	// プレイヤー画像の縦幅

	// Player hitbox size
	constexpr int PLAYER_HIT_SIZE_X = 40;	// プレイヤーの当たり判定の横幅
	constexpr int PLAYER_HIT_SIZE_Y = 60;	// プレイヤーの当たり判定の縦幅

	// ==========================
	// Animation
	// ==========================
	constexpr int ANIM_PATTERN_NUM = 4;	// アニメーションのパターン数
	constexpr int ANIM_TYPE_NUM = 4;	// アニメーションの種類数

	constexpr float ANIM_FPS = 12.0f;	// アニメーションのFPS

	constexpr const char* ANIM_IMG_PATH = "img/player.png";	// アニメーション画像のパス
}
