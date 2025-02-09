#pragma once
#include "Novice.h"
#include "Obj.h"
#include "Collision.h"
#include "Player.h"
#include "Enemy.h"
class Game
{
public:
	// メンバ関数
	Game();                                 // コンストラクタ
	~Game();                                // デストラクタ
	void Update(char* keys, char* preKeys); // 更新処理
	void Draw();                            // 描画処理
	// playerとenemyの包含
	Player* player; // プレイヤー
	Enemy* enemy;   // 敵
private:
	// メンバ変数
	int playerHpBarHandle; // プレイヤーのHPバー
	int enemyRespawnTimer; // 敵のリスポーンタイマー
	// 関数
	void PlayerUpdate(char* keys, char* preKeys); // プレイヤーの更新処理
	void EnemyUpdate();                           // 敵の更新処理
	void Collision();                             // シーン内の当たり判定を管理する
};