#include <Novice.h>

const char kWindowTitle[] = "LC1B_12_クロカワツバサ_タイトル";
const int kWindowSizeX = 1280;
const int kWindowSizeY = 720;


float powf(float base, float exponent) {
	if (exponent == 0) {
		return 1;
	}

	return base * powf(base, exponent - 1);
}


struct Vector2 {
	float x;
	float y;
};

// ボール構造体
struct Ball {
	Vector2 pos_;
	float radius_;
	int color_;
	Vector2 startPos_;
	Vector2 endPos_;

	float t_;
	int moveTime_;

	Ball();

	//描画
	void Draw();

	//更新処理
	void Update();
};
// Windowsアプリでのエントリーポイント(main関数)
int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {

	// ライブラリの初期化
	Novice::Initialize(kWindowTitle, kWindowSizeX, kWindowSizeY);

	const int kMaxBall = 4;

	Ball ball[kMaxBall];

	for (int i = 0; i < kMaxBall; i++) {

		ball[i].startPos_.y = ((kWindowSizeY / kMaxBall) * float(i)) + ball[i].radius_;
		ball[i].endPos_.y = ball[i].startPos_.y;

		//初期地点を代入
		ball[i].pos_ = ball[i].startPos_;
	}

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

		///
		/// ↑更新処理ここまで
		///

		///
		/// ↓描画処理ここから
		///

		for (int i = 0; i < kMaxBall; i++) {
		
			ball[i].Draw();

			Novice::ScreenPrintf(20, 20 + 20 * i, "%f,%f", ball[i].pos_.x, ball[i].pos_.y);
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


Ball::Ball() {

	radius_ = 50.0f;


	startPos_ = {
	radius_,
	0.0f
	};

	endPos_ = {
		kWindowSizeX - radius_,
		0.0f
	};

	pos_ = startPos_;

	color_ = 0xff0000ff;


	moveTime_ = 120;
}

void Ball::Update() {

	t_ += (1.0f / moveTime_);
}

//描画
void Ball::Draw() {

	Novice::DrawEllipse(
		int(pos_.x),
		int(pos_.y),
		int(radius_),
		int(radius_),
		0.0f,
		color_,
		kFillModeSolid
	);
}