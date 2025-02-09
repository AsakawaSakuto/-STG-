#include"Collision.h"

bool CircleCollision(Obj &A, Obj &B)
{
	float X = A.GetPos().x - B.GetPos().x;
	float Y = A.GetPos().y - B.GetPos().y;
	float XY = sqrtf(X * X + Y * Y);
	if (XY <= A.GetRad() + B.GetRad()) // 当たっているならtreu そうじゃないならfalseを返す
	{
		return true;
	}
	else
	{
		return false;
	}
}