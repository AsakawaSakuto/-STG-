#pragma once
#include "Novice.h"
#include "Obj.h"
#include "Collision.h"
#include "title.h"
#include "Game.h"
// シーン分け
enum SCENE
{
	TITLE,
	GAME,
};
// シーンを管理するクラス
class SceneManager
{
public:
	// メンバ関数
	SceneManager();                              // コンストラクタ
	void ChangeScene(char* keys, char* preKeys); // シーンの切り替えを管理する
	void Update(char* keys, char* preKeys);      // シーンの更新処理
	void Draw();                                 // シーンの描画処理
private:
	// メンバ変数
	int sceneName; // シーンを管理する変数
	Title* title;  // タイトルクラス
	Game* game;    // ゲームクラス
};