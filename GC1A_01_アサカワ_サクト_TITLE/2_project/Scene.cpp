#include"Scene.h"

SceneManager::SceneManager()
{
	title = new Title; // タイトルクラスをnew
	game = nullptr;    // ゲームクラスにnullを入れる
	sceneName = TITLE; // 最初の画面はタイトルにする
}

void SceneManager::ChangeScene(char* keys, char* preKeys) // シーンの切り替えを管理
{
	switch (sceneName)
	{
	case TITLE:
		if (keys[DIK_Z] && !preKeys[DIK_Z]) // Zキーでゲームシーン
		{
			sceneName = GAME;
			if (title != nullptr) // タイトルクラスをdelete
			{
				delete title;
				title = nullptr;
			}
			if (game == nullptr) // ゲームクラスをnew
			{
				game = new Game;
			}
		}
		break;
	case GAME:
		if (keys[DIK_X] && !preKeys[DIK_X] || game->player->hp == 0) // Xキー or　HP0でタイトルに戻る
		{
			sceneName = TITLE;
			if (game != nullptr) // ゲームクラスをdelete
			{
				delete game;
				game = nullptr;
			}
			if (title == nullptr) // タイトルクラスをnew
			{
				title = new Title;
			}
		}
		break;
	}
}
// シーンに応じてUpdateを呼び出す
void SceneManager::Update(char* keys, char* preKeys)
{
	switch (sceneName)
	{
	case TITLE:
		if (title != nullptr)
		{
			title->Update();
		}
		break;
	case GAME:
		if (game != nullptr)
		{
			game->Update(keys, preKeys);
		}
		break;
	}
	ChangeScene(keys, preKeys);
}
// シーンに応じてDrawを呼び出す
void SceneManager::Draw()
{
	switch (sceneName)
	{
	case TITLE:
		if (title != nullptr)
		{
			title->Draw();
		}
		break;
	case GAME:
		if (game != nullptr)
		{
			game->Draw();
		}
		break;
	}
}