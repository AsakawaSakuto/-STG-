#include"Player.h"

Player::Player() // コンストラクタ
{
	pos_ = {100.f,360.f}; // 初期座標XY
	size_ = {};
	speed_ = {};
	radius_ = {32.f};     // プレイヤーの半径
	for (int i = 0; i < BULLET_MAX; i++) 
	{
		bullet[i] = nullptr; // 弾に全部nullを入れる
	}
	hp = 3;               //HPを代入
	bulletSpawnTimer = 0; //スポーンタイマーの初期化
	invincibleTimer = 0;  //無敵時間の初期化
	isInvincible = false; //無敵フラグの初期化 false
	shake.pos = {};
	shake.setRange = 61;    // シェイクの範囲
	shake.offSetRange = 30; // シェイクのマイナス範囲
}

void Player::Update() // 更新処理
{
	pos_.x += speed_.x; // 常に速度を加算
	pos_.y += speed_.y;
	// 画面外にいかない処理
	if (pos_.y - radius_ <= SCREEN_TOP)
	{
		pos_.y = SCREEN_TOP + radius_;    // 画面上を超えない
	}
	else if (pos_.y + radius_ >= SCREEN_BOTTOM)
	{
		pos_.y = SCREEN_BOTTOM - radius_; // 画面下を超えない
	}
	if (pos_.x - radius_ <= SCREEN_LEFT)
	{
		pos_.x = SCREEN_LEFT + radius_;   // 画面左を超えない
	}
	else if (pos_.x + radius_ >= SCREEN_RIGHT)
	{
		pos_.x = SCREEN_RIGHT - radius_;  // 画面右を超えない
	}
	for (int i = 0; i < BULLET_MAX; i++)
	{
		if (bullet[i] != nullptr) 
		{
			bullet[i]->Update();                       // 弾がnullじゃないならUpdateを呼ぶ
			if (bullet[i]->GetPos().x >= SCREEN_RIGHT) // 画面右端でdelete nullを入れる
			{
				delete bullet[i];
				bullet[i] = nullptr;
			}
		}
	}
	if (isInvincible) // 無敵状態なら
	{
		ShakeUpdate();     // シェイクをする
		invincibleTimer++; // タイマーを回す
		if (invincibleTimer >= PLAYER_INVICIBLETIMER_MAX) // 上限越え
		{
			invincibleTimer = 0;    // タイマーを0にする
			isInvincible = false;   // フラグをfalse
			shake.setRange = 61;    // シェイクの範囲を戻す
			shake.offSetRange = 30; // シェイクのマイナス範囲を戻す
		}
	}
}

void Player::Draw() // 描画処理
{
	for (int i = 0; i < BULLET_MAX; i++)
	{
		if (bullet[i] != nullptr)
		{
			bullet[i]->Draw(); // 弾がnullじゃないなら描画
		}
	}
	if (isInvincible)
	{
		if (invincibleTimer % 2 == 0) // 無敵状態なら点滅
		{
			Vector2 vPos = { pos_.x + shake.pos.x,pos_.y + shake.pos.y };
			DrawEllipseFloat(vPos, radius_, RED, true);
		}
	}
	else // 無敵状態じゃないなら描画
	{
		DrawEllipseFloat(pos_, radius_, RED, true);
	}
}

void Player::ShakeUpdate() // シェイクを管理
{
	if (isInvincible) // 無敵状態なら
	{
		if (invincibleTimer % 6 == 0) // 6フレームごとに範囲を狭くする
		{
			shake.setRange -= 6;
			shake.offSetRange -= 3;
		}
		shake.ShakeSpawn(); // シェイクを生成
	}
}