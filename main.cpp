#include <Novice.h>

const char kWindowTitle[] = "6044_ゲームタイトル";

const int kWindowWidth = 1280; // ウィンドウの横幅
const int kWindowHeight = 720; // ウィンドウの縦幅

enum Scene { //列挙型　enum
	TITLE,//0
	GAME,//1
	CLEAR //2
};

// Windowsアプリでのエントリーポイント(main関数)
int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {

	// ライブラリの初期化
	Novice::Initialize(kWindowTitle, kWindowWidth, kWindowHeight);

	int currentScene = Scene::TITLE; //最初の背景

	// キー入力結果を受け取る箱
	char keys[256] = { 0 };
	char preKeys[256] = { 0 };

	// ウィンドウの×ボタンが押されるまでループ
	while (Novice::ProcessMessage() == 0) {
		// フレームの開始
		Novice::BeginFrame();

		// キー入力を受け取る
		memcpy(preKeys, keys, 256);
		Novice::GetHitKeyStateAll(keys);

		///
		/// ↓更新処理ここから
		///

		switch (currentScene) {
		case Scene::TITLE:
			if (keys[DIK_SPACE] && preKeys[DIK_SPACE] == 0) {

				currentScene = Scene::GAME;
			}
			break;
		case Scene::GAME:
			if (keys[DIK_SPACE] && preKeys[DIK_SPACE] == 0) {

				currentScene = Scene::CLEAR;
			}
			break;
		case Scene::CLEAR:
			if (keys[DIK_SPACE] && preKeys[DIK_SPACE] == 0) {

				currentScene = Scene::TITLE;
			}
			break;
		}

		///
		/// ↑更新処理ここまで
		///

		///
		/// ↓描画処理ここから
		///

		switch (currentScene) {
		case Scene::TITLE:
			Novice::DrawBox(0, 0, kWindowWidth, kWindowHeight, 0.0f, WHITE, kFillModeSolid);
			break;
		case Scene::GAME:
			Novice::DrawBox(0, 0, kWindowWidth, kWindowHeight, 0.0f, RED, kFillModeSolid);
			break;
		case Scene::CLEAR:
			Novice::DrawBox(0, 0, kWindowWidth, kWindowHeight, 0.0f, BLACK, kFillModeSolid);
			break;
		}

		///
		/// ↑描画処理ここまで
		///

		// フレームの終了
		Novice::EndFrame();

		// ESCキーが押されたらループを抜ける
		if (preKeys[DIK_ESCAPE] == 0 && keys[DIK_ESCAPE] != 0) {
			break;
		}
	}

	// ライブラリの終了
	Novice::Finalize();
	return 0;
}