#pragma once
#include"Obj.h"
#define BULLET_MAX 64     // 弾の生成できる上限数
class Bullet : public Obj // Objクラスを継承
{
public:
	// メンバ関数
	Bullet();               // コンストラクタ
	void Update() override; // 更新処理
	void Draw() override;   // 描画処理
	unsigned int color;     // 弾の色
private:
};