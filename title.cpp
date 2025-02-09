#include"title.h"
#include"Draw.h"
Title::Title() // 画像をload
{
	titleHandle = Novice::LoadTexture("./Resouces/title.png");
}

Title::~Title() // 画像をUnload
{
	Novice::UnloadTexture(titleHandle);
}

void Title::Update() // 更新処理
{
	
}

void Title::Draw() // 描画処理
{
	Novice::DrawSprite(0, 0, titleHandle, 1.f, 1.f, 0.f, WHITE);
}