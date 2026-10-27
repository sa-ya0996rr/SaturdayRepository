#include "Player.h"
#include "Map.h"
#include "DxLib.h"

//
// アニメーション方向
//
namespace
{
	constexpr int ANIM_DOWN = 0;
	constexpr int ANIM_UP = 1;
	constexpr int ANIM_LEFT = 2;
	constexpr int ANIM_RIGHT = 3;
}

// 
// コンストラクタ
//
Player::Player()
{
	x = 0.0f;
	y = 0.0f;

	velocityX = 0.0f;
	velocityY = 0.0f;

	animTimer = 0.0f;

	animNowType = ANIM_DOWN;
	animNowPattern = 1;
	animNowIndex = 1;
	
	drawOffsetX = 0;
	drawOffsetY = 0;

	for (int i = 0; i < Config::ANIM_PATTERN_NUM * Config::ANIM_TYPE_NUM; i++);
	{
		playerImg[i] = -1;
	}
}

// 
// デストラクタ
//
Player::~Player()
{
	// プレイヤー画像の解放
	for (int i = 0; i < Config::ANIM_PATTERN_NUM * Config::ANIM_TYPE_NUM; i++)
	{
		if (playerImg[i] != -1)
		{
			DeleteGraph(playerImg[i]);
			playerImg[i] = -1;
		}
	}
}


// 
// 初期化
//
bool Player::Init()
{
	// プレイヤーの初期位置
	x = Config::PLAYER_START_X;
	y = Config::PLAYER_START_Y;

	velocityX = 0.0f;
	velocityY = 0.0f;

	animTimer = 0.0f;

	animNowType = ANIM_DOWN;

	animNowPattern = -1;

	animNowIndex = animNowPattern + animNowType * Config::ANIM_PATTERN_NUM;

	// プレイヤー画像の読み込み
	int result = LoadDivGraph(
		Config::ANIM_IMG_PATH,
		Config::ANIM_PATTERN_NUM * Config::ANIM_TYPE_NUM,
		Config::ANIM_PATTERN_NUM, Config::ANIM_TYPE_NUM,
		Config::PLAYER_IMG_SIZE_X, Config::PLAYER_IMG_SIZE_Y,
		playerImg);

	if (result != 0)
	{
		return false;
	}

	// 描画オフセットの計算
	drawOffsetX = (Config::PLAYER_IMG_SIZE_X - Config::PLAYER_HIT_SIZE_X) / 2;
	drawOffsetY = (Config::PLAYER_IMG_SIZE_Y - Config::PLAYER_HIT_SIZE_Y) / 2;
	return true;
}

// 
// 更新
//
void Player::Update(float deltaTime, const Map& map)
{
	// 速度リセット
	velocityX = 0.0f;
	velocityY = 0.0f;

	bool isMoving = false;

	if (CheckHitKey(KEY_INPUT_UP) != 0)
	{
		velocityY = -Config::PLAYER_MOVE_SPEED;
		animNowType = ANIM_UP;
		isMoving = true;
	}
	else if (CheckHitKey(KEY_INPUT_DOWN) != 0)
	{
		velocityY = Config::PLAYER_MOVE_SPEED;
		animNowType = ANIM_DOWN;
		isMoving = true;
	}
	if (CheckHitKey(KEY_INPUT_LEFT) != 0)
	{
		velocityX = -Config::PLAYER_MOVE_SPEED;
		animNowType = ANIM_LEFT;
		isMoving = true;
	}
	else if (CheckHitKey(KEY_INPUT_RIGHT) != 0)
	{
		velocityX = Config::PLAYER_MOVE_SPEED;
		animNowType = ANIM_RIGHT;
		isMoving = true;
	}

	// 移動量の計算
	float moveX = velocityX * deltaTime;
	float moveY = velocityY * deltaTime;

	// X軸方向の衝突処理
	x += moveX;

	map.ResolveHorizontalCollision(
		x, y,
		Config::PLAYER_HIT_SIZE_X, Config::PLAYER_HIT_SIZE_Y,
		moveX);

	// Y軸方向の衝突処理
	y += moveY;

	map.ResolveVerticalCollision(
		x, y,
		Config::PLAYER_HIT_SIZE_X, Config::PLAYER_HIT_SIZE_Y,
		moveY);

	// アニメーションの更新
	if (isMoving)
	{
		animTimer += deltaTime;

		if (animTimer >= 1.0f / Config::ANIM_FPS)
		{
			animTimer = 0.0f;
			animNowPattern++;
			animNowPattern% = Config::ANIM_PATTERN_NUM;
		}
	}
	else
	{
		animNowPattern = 1;
	}

	// 描画する画像番号
	animNowIndex = animNowPattern + animNowType * Config::ANIM_PATTERN_NUM;
}

// 
// 描画
//
void Player::Draw() const
{
	DrawGraph(
		static_cast<int>(x) - drawOffsetX,
		static_cast<int>(y) - drawOffsetY,
		playerImg[animNowIndex],
		true);
	// 当たり判定の描画
	DrawBox(
		static_cast<int>(x),
		static_cast<int>(y),
		static_cast<int>(x + Config::PLAYER_HIT_SIZE_X - 1),
		static_cast<int>(y + Config::PLAYER_HIT_SIZE_Y - 1),
		GetColor(255, 0, 0), false);
}