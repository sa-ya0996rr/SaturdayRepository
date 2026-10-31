#include "Collision.h"

bool Collision::IsHitRect(
	float left1,
	float top1,
	float right1,
	float bottom1,

	float left2,
	float top2,
	float right2,
	float bottom2)
{
	return
		left1 < right2 &&
		left2 < right1 &&
		top1 < bottom2 &&
		top2 < bottom1;
}