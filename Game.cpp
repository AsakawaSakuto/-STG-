#include"Game.h"

Game::Game() // コンストラクタ
{
	player = new Player;                                                   // playerクラスをnew 
	enemy = new Enemy;                                                     // enemyクラスをnew
	playerHpBarHandle = Novice::LoadTexture("./Resouces/playerHpBar.png"); // HPバーをload
	enemyRespawnTimer = 0;                                                 // リスポーンタイマーを初期化
}

Game::~Game() // デストラクタ
{
	if (player != nullptr) // プレイヤーをdelete
	{
		delete player;
		player = nullptr;
	}
	if (enemy != nullptr) // 敵をdelete
	{
		delete enemy;
		enemy = nullptr;
	}
	Novice::UnloadTexture(playerHpBarHandle); // HPバーをUnload
}

void Game::Update(char* keys, char* preKeys) // 更新処理
{
	PlayerUpdate(keys, preKeys); // プレイヤーの更新処理
	EnemyUpdate();               // 敵の更新処理
	Collision();                 // 当たり判定を管理
}

void Game::Draw() // 描画処理
{
	DrawBoxInt({ 640,360 }, { 1280,720 }, 0x8d8d8dff, true);
	if (player != nullptr) // HPバー
	{
		DrawBoxInt({ 0,0 }, { 256 * static_cast<int>(player->hp + 1),256 }, GREEN, true);
	}
	Novice::DrawSprite(0, 0, playerHpBarHandle, 1.f, 1.f, 0.f, WHITE);

	if (enemy != nullptr) // 敵の描画
	{
		if (enemy->isInvincible)
		{
			if (enemyRespawnTimer >= 90 && enemyRespawnTimer % 6 == 0) // 敵がリスポーン直前に点滅
			{
				DrawEllipseFloat({ enemy->GetPos().x,enemy->GetPos().y}, {32.f}, BLUE, true);
			}
		}
		else // 生きているときに描画
		{
			enemy->Draw();
		}
	}
	if (player != nullptr) // プレイヤーの描画
	{
		player->Draw();
	}
}

void Game::PlayerUpdate(char* keys, char* preKeys) // プレイヤーの更新処理
{
	if (player != nullptr)
	{
		player->Update();
		// キー入力で速度を代入 入力なしで速度を0にする
		if (keys[DIK_LEFT])
		{
			player->SetSpeedX(-5.f); // 左
		} 
		else if (keys[DIK_RIGHT])
		{
			player->SetSpeedX(5.f);  // 右
		}
		else
		{
			player->SetSpeedX(0.f); 
		}
		if (keys[DIK_UP])
		{
			player->SetSpeedY(-5.f);  // 上
		} 
		else if (keys[DIK_DOWN])
		{
			player->SetSpeedY(5.f);   // 下
		} 
		else
		{
			player->SetSpeedY(0.f);
		}
		// Zキー長押しでタイマーを回す
		if (keys[DIK_Z])
		{
			player->bulletSpawnTimer++;
			if (player->bulletSpawnTimer >= PLAYER_BULLET_SPAWNTIMER_MAX) // 上限越えで弾をスポーン
			{
				player->bulletSpawnTimer = 0; // タイマーを0に戻す
				for (int i = 0; i < BULLET_MAX; i++)
				{
					if (player->bullet[i] == nullptr) // nullなら生成
					{
						player->bullet[i] = new Bullet;              // new
						player->bullet[i]->SetPos(player->GetPos()); // posを代入
						player->bullet[i]->SetRad(16.f);             // radiusを代入
						player->bullet[i]->SetSpeedX(10.f);          // speedを代入
						player->bullet[i]->color = RED;              // 色を代入
						break;
					}
				}
			}
		} 
		else
		{
			player->bulletSpawnTimer = 0; // 押されてないならタイマーを0にする
		}
		if (keys[DIK_C] && !preKeys[DIK_C]) // Cキー入力でHPを全回復
		{
			player->hp = 3;
		}
	}
}

void Game::EnemyUpdate() // 敵の更新処理
{
	if (enemy != nullptr)
	{
		// プレイヤーの弾に当たったら
		if (enemy->isInvincible)
		{
			enemyRespawnTimer++; // リスポーンタイマーを回す
			if (enemyRespawnTimer >= ENEMY_RESPAWNTIMER_MAX) // 上限越えで復活
			{
				enemyRespawnTimer = 0;       // タイマーを0にする
				enemy->isInvincible = false; // フラグを戻す
			}
			for (int i = 0; i < BULLET_MAX; i++) //弾を全てdeleteする
			{
				delete enemy->bullet[i];
				enemy->bullet[i] = nullptr;
			}
		}
		else
		{
			enemy->Update(); // 生きているときに更新処理
		}
	}
}

void Game::Collision() // 当たり判定を管理
{
	// プレイヤー と 敵
	if (player != nullptr && enemy != nullptr)
	{
		if (!player->isInvincible)
		{
			if (CircleCollision(*player, *enemy)) // 当たったら
			{
				player->hp--;                // プレイヤーのHPをデクリメント
				player->isInvincible = true; // プレイヤーを無敵にする
			}
		}
	}
	for (int i = 0; i < BULLET_MAX; i++)
	{
		// プレイヤーの弾 と 敵
		if (player != nullptr)
		{
			if (player->bullet[i] != nullptr && enemy != nullptr)
			{
				if (!enemy->isInvincible)
				{
					if (CircleCollision(*player->bullet[i], *enemy)) // 当たったら
					{
						enemy->isInvincible = true;  // 敵の死亡フラグをtrueにする
						delete player->bullet[i];    // 当たったプレイヤーの弾をdelete
						player->bullet[i] = nullptr; // 当たったプレイヤーの弾にnullを入れる
					}
				}
			}
		}
		// プレイヤー と 敵の弾
		if (enemy != nullptr)
		{
			if (player != nullptr && enemy->bullet[i] != nullptr)
			{
				if (!player->isInvincible)
				{
					if (CircleCollision(*player, *enemy->bullet[i])) // 当たったら
					{
						player->hp--;                // プレイヤーのHPをデクリメント
						player->isInvincible = true; // プレイヤーを無敵にする
						delete enemy->bullet[i];     // 当たった敵の弾をdelete
						enemy->bullet[i] = nullptr;  // 当たった敵の弾にnullを入れる
					}
				}
			}
		}
	}
}