#pragma once
#include"Obj.h"
#include"bullet.h"
#include"Shake.h"
#define ENEMY_BULLET_SPAWNTIMER_MAX 60 // 敵の弾のスポーンタイマーの上限
#define ENEMY_RESPAWNTIMER_MAX 180     // 敵のリスポーンタイマーの上限
class Enemy : public Obj               // Objクラスを継承
{
public:
	// メンバ関数
	Enemy();                // コンストラクタ
	void Update() override; // 更新処理
	void Draw() override;   // 描画処理
	// メンバ変数
	bool isInvincible;      // 生きているか否かを判定
	int respawnTimer;       // リスポーンタイマー
	int bulletSpawnTimer;   // 弾のスポーンタイマー
	// Bulletクラスを包含
	Bullet* bullet[BULLET_MAX]; // Bulletクラス
	// シェイク
	Shake shake;        // シェイククラスを呼び出す
	void ShakeUpdate(); // シェイクを管理
private:
};