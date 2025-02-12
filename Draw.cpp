#include"Draw.h"
void DrawBoxInt(Vector2_Int pos, Vector2_Int size, unsigned int color, bool kfillMode)
{
	if (kfillMode)
	{
		Novice::DrawBox(pos.x - size.x / 2, pos.y - size.y / 2, size.x, size.y, 0.f, color, kFillModeSolid);
	}
	else
	{
		Novice::DrawBox(pos.x - size.x / 2, pos.y - size.y / 2, size.x, size.y, 0.f, color, kFillModeWireFrame);
	}
}
void DrawBoxFloat(Vector2 pos, Vector2 size, unsigned int color, bool kfillMode)
{
	if (kfillMode)
	{
		Novice::DrawBox(static_cast<int>(pos.x - size.x / 2.f), static_cast<int>(pos.y - size.y / 2.f), static_cast<int>(size.x), static_cast<int>(size.y), 0.f, color, kFillModeSolid);
	} 
	else
	{
		Novice::DrawBox(static_cast<int>(pos.x - size.x / 2.f), static_cast<int>(pos.y - size.y / 2.f), static_cast<int>(size.x), static_cast<int>(size.y), 0.f, color, kFillModeWireFrame);
	}
}
void DrawEllipseInt(Vector2_Int pos, int radius, unsigned int color, bool kfillMode)
{
	if (kfillMode)
	{
		Novice::DrawEllipse(pos.x, pos.y, radius, radius, 0.f, color, kFillModeSolid);
	} 
	else
	{
		Novice::DrawEllipse(pos.x, pos.y, radius, radius, 0.f, color, kFillModeWireFrame);
	}
}
void DrawEllipseFloat(Vector2 pos, float radius, unsigned int color, bool kfillMode)
{
	if (kfillMode)
	{
		Novice::DrawEllipse(static_cast<int>(pos.x), static_cast<int>(pos.y), static_cast<int>(radius), static_cast<int>(radius), 0.f, color, kFillModeSolid);
	}																						   
	else																					   
	{																						   
		Novice::DrawEllipse(static_cast<int>(pos.x), static_cast<int>(pos.y), static_cast<int>(radius), static_cast<int>(radius), 0.f, color, kFillModeWireFrame);
	}
}