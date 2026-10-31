#pragma once

class Collision
{
public:
	/// <summary>
	/// 2‚Â‚Ì‹éŒ`‚ªÕ“Ë‚µ‚Ä‚¢‚é‚©‚ğ”»’è‚·‚é
	/// </summary>
	static bool IsHitRect(
		float left1,
		float top1,
		float right1,
		float bottom1,
		float left2,
		float top2,
		float right2,
		float bottom2);
};