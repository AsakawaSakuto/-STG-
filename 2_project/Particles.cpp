#include"Particles.h"

BulletParticles::BulletParticles() // コンストラクタ
{
	pos_ = {};
	size_ = {};
	speed_ = {};
	radius_ = {};
	color = WHITE;
}

void BulletParticles::Update() // 更新処理
{
	radius_ -= 1.f; // サイズを小さくする
}

void BulletParticles::Draw() // 描画処理
{
	DrawEllipseFloat(pos_, radius_, color, true);
}