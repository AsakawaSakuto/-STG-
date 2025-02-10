#pragma once
#include"Obj.h"
#include"bullet.h"
#include"Shake.h"
#define PLAYER_BULLET_SPAWNTIMER_MAX 15 // プレイヤーの弾のスポーンタイマーの上限
#define PLAYER_INVICIBLETIMER_MAX 60    // プレイヤーの無敵時間の上限
class Player : public Obj               // Objクラスを継承
{
public:
	// メンバ関数
	Player();               // コンストラクタ
	void Update() override; // 更新処理
	void Draw() override;   // 描画処理
	// メンバ変数
	int hp;
	int bulletSpawnTimer;	// 弾のスポーンタイマー
	int invincibleTimer;    // 無敵時間を測るタイマー
	bool isInvincible;      // 無敵かどうかのフラグ
	// Bulletクラスを包含
	Bullet* bullet[BULLET_MAX]; // Bulletクラス
private: 
	void ShakeUpdate(); // シェイクを管理
	Shake shake;        // シェイククラスを呼び出す
};