#include"Enemy.h"

Enemy::Enemy() // コンストラクタ
{
	pos_ = { 1180.f,360.f }; // 初期座標XY
	size_ = {};
	speed_ = {0.f,-5.f};     // 速度XY
	radius_ = { 32.f };      // 半径
	for (int i = 0; i < BULLET_MAX; i++)
	{
		bullet[i] = nullptr; // 弾に全部nullを入れる
	}
	respawnTimer = 0;     // リスポーンタイマーを初期化
	bulletSpawnTimer = 0; // 弾のスポーンタイマーを初期化
	isInvincible = false; // 死亡フラグを初期化 false
	shake.pos = {};
	shake.setRange = 61;    // シェイクの範囲
	shake.offSetRange = 30; // シェイクのマイナス範囲
}

void Enemy::Update() // 更新処理
{
	pos_.y += speed_.y; // 速度Yを加算
	if (pos_.y - radius_ <= SCREEN_TOP) 
	{
		speed_.y *= -1.f; // 画面上に到達で速度を反転
	}
	else if (pos_.y + radius_ >= SCREEN_BOTTOM)
	{
		speed_.y *= -1.f; // 画面下に到達で速度を反転
	}

	bulletSpawnTimer++; // 弾の生成タイマーを回す
	if (bulletSpawnTimer >= ENEMY_BULLET_SPAWNTIMER_MAX) // 上限に到達で生成
	{
		bulletSpawnTimer = 0; // タイマーを0に戻す
		for (int i = 0; i < BULLET_MAX; i++)
		{
			if (bullet[i] == nullptr) // nullなら生成
			{
				bullet[i] = new Bullet;      // new
				bullet[i]->SetPos(pos_);     // posを代入
				bullet[i]->SetRad(16.f);     // radiusを代入
				bullet[i]->SetSpeedX(-10.f); // speedXを代入
				bullet[i]->color = BLUE;     // 色を代入
				break;
			}
		}
	}
	for (int i = 0; i < BULLET_MAX; i++)
	{
		if (bullet[i] != nullptr) // nullじゃないならUpdateを呼ぶ
		{
			bullet[i]->Update();
			if (bullet[i]->GetPos().x <= SCREEN_LEFT) //画面左端到達でdelete nullを入れる
			{
				delete bullet[i];
				bullet[i] = nullptr;
			}
		}
	}
}
void Enemy::Draw() // 更新処理
{
	for (int i = 0; i < BULLET_MAX; i++)
	{
		if (bullet[i] != nullptr) // 弾がnullじゃないなら描画
		{
			bullet[i]->Draw();
		}
	}
	Vector2 vPos = { pos_.x + shake.pos.x,pos_.y + shake.pos.y };
	DrawEllipseFloat(vPos, radius_, BLUE, true);
}

void Enemy::ShakeUpdate() // シェイクを管理
{
	if (respawnTimer >= 120)
	{
		if (respawnTimer % 6 == 0) // 6フレームごとに範囲を狭くする
		{
			shake.setRange -= 6;
			shake.offSetRange -= 3;
		}
		shake.ShakeSpawn(); // シェイクを生成
	}
}