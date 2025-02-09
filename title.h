#pragma once
#include "Novice.h"
#include "Obj.h"
#include "Collision.h"
// タイトルシーンクラス
class Title
{
public:
	// メンバ関数
	Title();       // コンストラクタ
	~Title();      // デストラクタ
	void Update(); // 更新処理
	void Draw();   // 描画処理
private:
	// メンバ変数
	int titleHandle; // タイトル画面の画像Handle
};
