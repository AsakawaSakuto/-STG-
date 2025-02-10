#pragma once
#include"Vector2.h"
#include"Obj.h"
class Shake
{
public:
	// メンバ関数
	Shake();           // コンストラクタ
	void ShakeSpawn(); // シェイクを生成
	//
	Vector2 pos;       // シェイクXY
	int setRange;      // シェイクの範囲
	int offSetRange;   // シェイクのマイナスする値
private:
};