#include"Shake.h"

Shake::Shake() // コンストラクタ
{
	pos = {};
	setRange = 0;
	offSetRange = 0;
}

void Shake::ShakeSpawn() // シェイクを生成
{
	pos.x = static_cast<float>(rand() % setRange - offSetRange);
	pos.y = static_cast<float>(rand() % setRange - offSetRange);
}
