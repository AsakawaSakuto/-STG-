#pragma once
#include"Obj.h"
#define PARTICLES_MAX 128                 // パーティクルの上限数
#define BULLET_PARTICLES_SPAWNTIMER_MAX 3 // 弾のパーティクルの生成タイマー上限
class BulletParticles : public Obj        // Objクラスを継承
{
public:
	// メンバ関数 変数
	BulletParticles();      // コンストラクタ
	void Update() override; // 更新処理
	void Draw() override;   // 描画処理
	unsigned int color;     // 色
private:
};