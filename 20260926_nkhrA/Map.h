#pragma once
#include "Config.h"

class Map
{
private:
	// 
	// マップデータ
	//
	unsigned char map[Config::MAP_Y_NUM][Config::MAP_X_NUM]
    {
        { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1 },
        { 1,0,0,0,0,0,0,0,0,0,0,0,1,0,0,1 },
        { 1,0,0,1,0,0,0,0,0,0,0,0,1,0,0,1 },
        { 1,0,1,0,1,0,0,0,0,1,0,0,0,0,0,1 },
        { 1,0,0,0,0,0,0,1,1,0,0,0,0,0,0,1 },
        { 1,0,0,0,0,0,0,1,1,0,0,0,0,0,0,1 },
        { 1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1 },
        { 1,0,0,0,0,0,0,0,0,0,0,0,0,1,0,1 },
        { 1,1,0,1,0,0,0,1,1,1,0,0,0,1,0,1 },
        { 1,0,1,0,0,0,0,1,0,0,0,0,0,0,0,1 },
        { 1,0,1,0,0,0,0,1,0,0,0,0,0,0,0,1 },
        { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1 }
    };

    // 
	// マップチップ画像
    //
	int mapChipImg[Config::MAP_IMG_X_NUM * Config::MAP_IMG_Y_NUM];

public:
	Map();
	~Map();

    //
    // 初期化
    //
    bool Init();

    // 
    // 描画
    // 
    void Draw();

    //
    // 衝突処理
    //
    bool ResolveHorizontalCollision(float& x, float y, float width, float height, float moveX) const;
    bool ResolveVerticalCollision(float x, float& y, float width, float height, float moveY) const;

    // 
    // マップ情報
    //
    unsigned char GetBlockType(int ix, int iy)const;
};