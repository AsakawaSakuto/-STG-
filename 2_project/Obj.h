#pragma once
#include "Vector2.h"
#include "Novice.h"
#include "Draw.h"
#define SCREEN_TOP 0.f      // 画面上端
#define SCREEN_BOTTOM 720.f // 画面下端
#define SCREEN_RIGHT 1280.f // 画面右端
#define SCREEN_LEFT 0.f     // 画面左端
/// <summary>
/// 新たにキャラクターを作る場合はこのクラスを継承する
/// </summary>
class Obj
{
public:
	// メンバ関数
	Obj();                                              // コンストラクタ
	~Obj();                                             // デストラクタ
	virtual void Update();                              // 更新処理
	virtual void Draw();                                // 描画処理
	Vector2 GetPos() const{ return pos_; }              // 座標XYのゲッター
	void SetPos(Vector2 pos) { pos_ = pos; }            // 座標XYのセッター
	Vector2 GetSize() const { return size_; }           // サイズXYのゲッター
	float GetRad()const { return radius_; }             // 半径のゲッター
	void SetRad(float radius) { radius_ = radius; }     // 半径のセッター
	void SetSpeedX(float speedX) { speed_.x = speedX; } // 速度Xのセッター
	void SetSpeedY(float speedY) { speed_.y = speedY; } // 速度Yのセッター
protected:
	// メンバ変数
	Vector2 pos_;   // 座標XY
	Vector2 speed_; // 速度XY
	Vector2 size_;  // サイズXY
	float radius_;  // 半径
};