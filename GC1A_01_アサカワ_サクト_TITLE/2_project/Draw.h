#pragma once
#include"Novice.h"
#include"Obj.h"
#include"Vector2.h"
/// <summary>
/// int型用のDrawBox
/// </summary>
/// <param name="pos">座標XY</param>
/// <param name="size">サイズXY</param>
/// <param name="color">色</param>
/// <param name="kfillMode">trueで塗りつぶしfalseで線のみ</param>
void DrawBoxInt(Vector2Int pos, Vector2Int size, unsigned int color, bool kfillMode);

/// <summary>
/// float型用のDrawBox int型にcastして描画
/// </summary>
/// <param name="pos">座標XY</param>
/// <param name="size">サイズXY</param>
/// <param name="color">色</param>
/// <param name="kfillMode">trueで塗りつぶしfalseで線のみ</param>
void DrawBoxFloat(Vector2 pos, Vector2 size, unsigned int color, bool kfillMode);

/// <summary>
/// int型用のDrawEllipse
/// </summary>
/// <param name="pos">座標XY</param>
/// <param name="radius">半径</param>
/// <param name="color">色</param>
/// <param name="kfillMode">trueで塗りつぶしfalseで線のみ</param>
void DrawEllipseInt(Vector2Int pos, int radius, unsigned int color, bool kfillMode);

/// <summary>
/// float型用のDrawEllipse int型にcastして描画
/// </summary>
/// <param name="pos">座標XY</param>
/// <param name="radius">半径</param>
/// <param name="color">色</param>
/// <param name="kfillMode">trueで塗りつぶしfalseで線のみ</param>
void DrawEllipseFloat(Vector2 pos, float radius, unsigned int color, bool kfillMode);