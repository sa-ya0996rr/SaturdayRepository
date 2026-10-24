#include "Collision.h"

bool Collision::IsHitRect(
	float x1,
	float y1,
	float width1,
	float height1,

	float x2,
	float y2,
	float width2,
	float height2)
{
	return
		left1 < right2&&
		left2 < right1&&
		top1 < bottom2&&
		top2 < bottom1;
}