#include "Bullet.h"

Bullet::Bullet() // コンストラクタ
{
	pos_ = {};
	size_ = {};
	speed_ = {};
	radius_ = {};
	color = WHITE;
	for (int i = 0; i < PARTICLES_MAX; i++)
	{
		particles[i] = nullptr;
	}
	particleSpawnTimer = 0;
}

void Bullet::Update() // 更新処理
{
	pos_.x += speed_.x; // 常に速度を加算
	ParticleSpawn();    // パーティクル生成関連を呼ぶ
}

void Bullet::Draw() // 描画処理
{
	for (int i = 0; i < PARTICLES_MAX; i++)
	{
		if (particles[i] != nullptr) // nullじゃないなら描画
		{
			particles[i]->Draw();
		}
	}
	DrawEllipseFloat(pos_, radius_, color, true);
}

void Bullet::ParticleSpawn() // パーティクル生成関数
{
	particleSpawnTimer++; // スポーンタイマーを回す
	if (particleSpawnTimer >= BULLET_PARTICLES_SPAWNTIMER_MAX) // タイマーの上限を越えると生成
	{
		particleSpawnTimer = 0; // タイマーを0に戻す
		for (int i = 0; i < PARTICLES_MAX; i++)
		{
			if (particles[i] == nullptr) // nullなら生成
			{
				particles[i] = new BulletParticles; // new
				particles[i]->SetPos(pos_);         // posを代入
				particles[i]->SetRad(radius_);      // radiusを代入
				particles[i]->color = color;        // 色を代入
				break;
			}
		}
	}
	for (int i = 0; i < PARTICLES_MAX; i++)
	{
		if (particles[i] != nullptr) // nullじゃないなら
		{
			particles[i]->Update();  // 更新処理を呼ぶ
			if (particles[i]->GetRad() <= 0.f) // radiusが0以下になったら
			{
				delete particles[i];    // delete
				particles[i] = nullptr; // nullを入れる
			}
		}
	}
}