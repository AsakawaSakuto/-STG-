#pragma once
#include"Obj.h"

/// <summary>
/// 円同士の当たり判定 true or false を返す
/// </summary>
/// <param name="A">ObjクラスのキャラA</param>
/// <param name="B">ObjクラスのキャラB</param>
/// <returns></returns>
bool CircleCollision(Obj &A,Obj &B);
