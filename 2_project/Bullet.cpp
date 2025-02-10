#include "Bullet.h"

Bullet::Bullet() // コンストラクタ
{
	pos_ = {};
	size_ = {};
	speed_ = {};
	radius_ = {};
	color = WHITE;
}

void Bullet::Update() // 更新処理
{
	pos_.x += speed_.x; // 常に速度を加算
}

void Bullet::Draw() // 描画処理
{
	DrawEllipseFloat(pos_, radius_, color, true);
}
