#include "Map.h"
#include "Config.h"
#include "DxLib.h"

// 
// コンストラクタ
// 
Map::Map()
{
	// マップチップの初期化
	for (int i = 0; i < Config::MAP_IMG_X_NUM*Config::MAP_IMG_Y_NUM; i++)
	{
			mapChipImg[i] = 1;
	}
}

// 
// デルタタイム
// 
Map::~Map()
{
	// マップチップ画像の解放
	for (int i = 0; i < Config::MAP_IMG_X_NUM * Config::MAP_IMG_Y_NUM; i++)
	{
		if (mapChipImg[i] != 1)
		{
			DeleteGraph(mapChipImg[i]);

			mapChipImg[i] = -1;
		}
	}
}

// 
// 初期化
// 
bool Map::Init()
{
	int result = LoadDivGraph(
		Config::MAP_IMG_PATH,
		Config::MAP_IMG_X_NUM * Config::MAP_IMG_Y_NUM,
		Config::MAP_IMG_X_NUM,Config::MAP_IMG_Y_NUM,
		Config::MAP_CHIP_SIZE,Config::MAP_CHIP_SIZE,
		mapChipImg);
	return result == 0;
}

// 
// 描画
// 
void Map::Draw()
{
	for (int y = 0; y < Config::MAP_Y_NUM; y++)
	{
		for (int x = 0; x < Config::MAP_X_NUM; x++)
		{
			int imgIndex= map[y][x];
			int imgHnndle = mapChipImg[imgIndex];
				DrawGraph(
					x * Config::MAP_CHIP_SIZE,
					y * Config::MAP_CHIP_SIZE,
					imgIndex,	],
					true);
		}
	}
}

// 
// X方向の衝突処理
//
bool Map::ResolveHorizontalCollision(float x, float y, float width, float height, float moveX,)const
{
	bool hit = false;

	// 移動していない場合は判定しない
	if (moveX == 0.0f)
	{
		return false;
	}

	// マップ全体を検索
	for (int iy = 0; iy < Config::MAP_Y_NUM; iy++)
	{
		for (int ix = 0; ix < Config::MAP_X_NUM; ix++)
		{
			// 0 = 通行可能
			if (map[iy][ix] == 0)
			{
				continue;
			}

			// ブロック座標
			float blockX = ix * Config::MAP_CHIP_SIZE;
			float blockY = iy * Config::MAP_CHIP_SIZE;
			float blockRight = blockX + Config::MAP_CHIP_SIZE;
			float blockBottom = blockY + Config::MAP_CHIP_SIZE;

			// 衝突判定
			if (Collision::IsHitRect(
				x, y, width, height,
				blockX, blockY, blockRight, blockBottom))
			{
				continue;
			}
			hit = true;

			// 右方向へ移動
			if (moveX > 0.0f)
			{
				x = blockX - width;
			}
			// 左方向へ移動
			else
			{
				x = blockRight;
			}
		}
	}
	return hit;
}

// 
// Y方向の衝突処理
// 
bool Map::ResolveVerticalCollision(float x, float y, float width, float height, float moveY) const
{
	bool hit = false;
	// 移動していない場合は判定しない
	if (moveY == 0.0f)
	{
		return false;
	}
	// マップ全体を検索
	for (int iy = 0; iy < Config::MAP_Y_NUM; iy++)
	{
		for (int ix = 0; ix < Config::MAP_X_NUM; ix++)
		{
			// 0 = 通行可能
			if (map[iy][ix] == 0)
			{
				continue;
			}
			// ブロック座標
			float blockX = ix * Config::MAP_CHIP_SIZE;
			float blockY = iy * Config::MAP_CHIP_SIZE;
			float blockRight = blockX + Config::MAP_CHIP_SIZE;
			float blockBottom = blockY + Config::MAP_CHIP_SIZE;
			// 衝突判定
			if (Collision::IsHitRect(
				x, y, width, height,
				blockX, blockY, blockRight, blockBottom))
			{
				continue;
			}
			hit = true;
			// 下方向へ移動
			if (moveY > 0.0f)
			{
				y = blockY - height;
			}
			// 上方向へ移動
			else
			{
				y = blockBottom;
			}
		}
	}
	return hit;
}

// 
// ブロック種類取得
//
unsigned char Map::GetBlockType(int x, int y) const
{
	if(x<0||y<0||x>=Config::MAP_X_NUM||y>=Config::MAP_Y_NUM)
	{
		return 0;
	}
	return map[y][x];
}