#pragma once
#include "Config.h"

class Map;

class Player
{
private:
	// ==========================
	// 座標
	// ==========================
	float x;
	float y;

	// ==========================
	// 速度
	// ==========================
	float velocityX;
	float velocityY;

	// ==========================
	// ジャンプ処理
	// ==========================
	float gravity;
	float jumpPower;

	// 接地判定
	bool onGround;

	// SPACEキーの入力状態
	bool jumpKeyPrev;

	// ==========================
	// アニメーション
	// ==========================
	float animTimer;

	int animNowType;
	int animNowPattern;
	int animNowIndex;

	// ==========================
	// 描画位置補正
	// ==========================
	int drawOffsetX;
	int drawOffsetY;

	// ==========================
	// プレイヤー画僧
	// ==========================
	int playerImg[Config::ANIM_PATTERN_NUM * Config::ANIM_TYPE_NUM];

public:
	Player();
	~Player();

	// ==========================
	// 初期化 
	//==========================
	bool Init();

	// ==========================
	// 更新
	// ==========================
	void Update(float deltaTime, const Map& map);

	// ==========================
	// 描画
	// ==========================
	void Draw() const;

};