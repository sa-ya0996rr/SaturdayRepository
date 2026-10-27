#pragma once
class Collision
{
public:
	/// <summary>
	/// 2つの矩形が衝突しているかを判定する
	/// </summary>
	/// <param name="x1">		矩形1の左端のX座標</param>
	/// <param name="y1">		矩形1の上端のY座標</param>
	/// <param name="width1">	矩形1の幅</param>
	/// <param name="height1">	矩形1の高さ</param>
	/// <param name="x2">		矩形2の左端のX座標</param>
	/// <param name="y2">		矩形2の上端のY座標</param>
	/// <param name="width2">	矩形2の幅</param>
	/// <param name="height2">	矩形2の高さ</param>
	/// <returns>衝突している場合はtrue、そうでない場合はfalse</returns>
	static bool IsHitRect(
		float x1,
		float y1,
		float width1,
		float height1,
		float x2,
		float y2,
		float width2,
		float height2);
}