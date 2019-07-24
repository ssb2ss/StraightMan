#include "GameScene.h"
#include "SceneManager.h"
#include "FileManager.h"

#include "MainScene.h"
#include "StageSelectScene.h"

GameScene::GameScene(int stage)
{
	player = new Player();
	currentStage = stage;
}

GameScene::~GameScene()
{
	delete player;
}

void GameScene::Start() {
	width = 108;
	height = 41;
	starCntY = 24;

	moveCount = 0;
	starCount = 3;

	SetMap();
	PrintMap();
	PlayGame();
}

void GameScene::SetMap() {

	// mapArray		| 0 : 빈공간 / 1 : 벽 / 2 : 플레이어 / 3 : 목적지
	// starCutLine	| [0] : 별 3개 커트라인 / [1] : 별 2개 커트라인 

	switch (currentStage) {
		case 1:
			starCutLine[0] = 13;
			starCutLine[1] = 19;
			mapArray[0]  = "111111111111111111111111111111111111111111111111111111";
			mapArray[1]  = "120000000000000000000000000000000000000000000000000001";
			mapArray[2]  = "100000000000000000000000000000000000000000000000000001";
			mapArray[3]  = "100000000000000000000000000000000000000000000000000001";
			mapArray[4]  = "100000000000000000000000000000000000000000000000000001";
			mapArray[5]  = "100000000000000000000000000000000000000000000000000001";
			mapArray[6]  = "111111111111111111111111111111111111111111111110000001";
			mapArray[7]  = "100000000000000000000000000000000000000000000000000001";
			mapArray[8]  = "100000000000000000000000000000000000000000000000000001";
			mapArray[9]  = "100000000000000000000000000000000000000000000000000001";
			mapArray[10] = "100000000000000000000000000000000000000000000000000001";
			mapArray[11] = "100000000000000000000000000000000000000000000000000001";
			mapArray[12] = "100000011111111111111111111111111111111111111111111111";
			mapArray[13] = "100000000000000000000000000000000000000000000000000001";
			mapArray[14] = "100000000000000000000000000000000000000000000000000001";
			mapArray[15] = "100000000000000000000000000000000000000000000000000001";
			mapArray[16] = "100000000000000000000000000000000000000000000000000001";
			mapArray[17] = "100000000000000000000000000000000000000000000000000001";
			mapArray[18] = "111111111111111111111111111111111111111111111110000001";
			mapArray[19] = "100000000000000000000000000000000000000000000000000001";
			mapArray[20] = "100000000000000000000000000000000000000000000000000001";
			mapArray[21] = "100000000000000000000000000000000000000000000000000001";
			mapArray[22] = "100000000000000000000000000000000000000000000000000001";
			mapArray[23] = "100000000000000000000000000000000000000000000000000001";
			mapArray[24] = "100000011111111111111111111111111111111111111111111111";
			mapArray[25] = "100000000000000000000000000000000000000000000000000001";
			mapArray[26] = "100000000000000000000000000000000000000000000000000001";
			mapArray[27] = "100000000000000000000000000000000000000000000000000001";
			mapArray[28] = "100000000000000000000000000000000000000000000000000001";
			mapArray[29] = "100000000000000000000000000000000000000000000000000001";
			mapArray[30] = "111111111111111111111111111111111111111111111110000001";
			mapArray[31] = "100000000000000000000000000000000000000000000000000001";
			mapArray[32] = "100000000000000000000000000000000000000000000000000001";
			mapArray[33] = "100000000000000000000000000000000000000000000000000001";
			mapArray[34] = "100000000000000000000000000000000000000000000000000001";
			mapArray[35] = "100000000000000000000000000000000000000000000000000001";
			mapArray[36] = "100011111111111111111111111111111111111111111111111111";
			mapArray[37] = "100000000000000000000000000000000000000000000000000001";
			mapArray[38] = "100000000000000000000000000000000000000000000000000001";
			mapArray[39] = "100000000000000000000000000000000000000000000000000031";
			mapArray[40] = "111111111111111111111111111111111111111111111111111111";
			break;
	}

}

void GameScene::PrintMap() {

	setBackgroundColor(ColorWhite);
	for (int i = 0; i < height; i++) {
		for (int j = 0; j < width / 2; j++) {
			gotoxy(2 + j * 2, 1 + i);
			if (mapArray[i][j] == '1') {
				setBackgroundColor(ColorWhite);
				std::cout << "  ";
			}
			else if (mapArray[i][j] == '2') {
				startX = j;
				startY = i;
				player->x = j;
				player->y = i;
				player->Render();
			}
			else if (mapArray[i][j] == '3') {
				setBackgroundColor(ColorLightBlue);
				std::cout << "  ";
				goalX = j;
				goalY = i;
			}
		}
	}

	setBackgroundColor(ColorBlack);
	UpdateMoveCount();

	setBackgroundColor(ColorLightRed);
	gotoxy(width + 4, 5);
	std::cout << "  ";
	setBackgroundColor(ColorBlack);
	std::cout << " : 플레이어";
	setBackgroundColor(ColorLightBlue);
	gotoxy(width + 4, 7);
	std::cout << "  ";
	setBackgroundColor(ColorBlack);
	std::cout << " : 목적지";
	gotoxy(width + 4, 11);
	std::cout << "방향키 (WASD) : 이동";
	gotoxy(width + 4, 13);
	std::cout << "R : 재시작";
	gotoxy(width + 4, 15);
	std::cout << "ESC : 메인화면";

	PrintStar();
}

void GameScene::PrintStar() {

	setBackgroundColor(ColorBlack);

	gotoxy(width + 12, starCntY);
	std::cout << "현재 별 개수";
	gotoxy(width + 12, starCntY + 2);
	std::cout << "★  ★  ★";
	gotoxy(width + 12, starCntY + 13);
	std::cout << "★";
	gotoxy(width + 24, starCntY + 13);
	std::cout << "☆";
	gotoxy(width + 36, starCntY + 13);
	std::cout << "☆";
	gotoxy(width + 12, starCntY + 14);
	std::cout << "★";
	gotoxy(width + 24, starCntY + 14);
	std::cout << "★";
	gotoxy(width + 36, starCntY + 14);
	std::cout << "☆";
	gotoxy(width + 12, starCntY + 15);
	std::cout << "★";
	gotoxy(width + 24, starCntY + 15);
	std::cout << "★";
	gotoxy(width + 36, starCntY + 15);
	std::cout << "★";
	gotoxy(width + 12, starCntY + 17);
	std::cout << starCutLine[0];
	gotoxy(width + 15, starCntY + 17);
	std::cout << "번";
	gotoxy(width + 24, starCntY + 17);
	std::cout << starCutLine[1];
	gotoxy(width + 27, starCntY + 17);
	std::cout << "번";
	gotoxy(width + 36, starCntY + 17);
	std::cout << "∞ 번";

	setBackgroundColor(ColorBlack);

}

void GameScene::PlayGame() {

	while (true) {
		if (_kbhit()) {

			char key = _getch();
			if (key == 27) { //ESC
				SceneManager::ChangeScene(new MainScene());
				break;
			}
			else if (key == 'R' || key == 'r') { //R
				RestartGame();
			}
			else if (key == 75 || key == 'A' || key == 'a') { //왼쪽
				int destX;
				for (destX = player->x; mapArray[player->y][destX - 1] != '1'; destX--);
				if (destX != player->x) {
					moveCount++;
					UpdateMoveCount();
				}
				player->Move(destX, player->y);
			}
			else if (key == 77 || key == 'D' || key == 'd') { // 오른쪽
				int destX;
				for (destX = player->x; mapArray[player->y][destX + 1] != '1'; destX++);
				if (destX != player->x) {
					moveCount++;
					UpdateMoveCount();
				}
				player->Move(destX, player->y);
			}
			else if (key == 72 || key == 'W' || key == 'w') { //위쪽
				int destY;
				for (destY = player->y; mapArray[destY - 1][player->x] != '1'; destY--);
				if (destY != player->y) {
					moveCount++;
					UpdateMoveCount();
				}
				player->Move(player->x, destY);
			}
			else if (key == 80 || key == 'S' || key == 's') { //아래쪽
				int destY;
				for (destY = player->y; mapArray[destY + 1][player->x] != '1'; destY++);
				if (destY != player->y) {
					moveCount++;
					UpdateMoveCount();
				}
				player->Move(player->x, destY);
			}

			if (player->x == goalX && player->y == goalY) {
				break;
			}

		}
	}

	GameClear();

}

void GameScene::RestartGame() {

	setBackgroundColor(ColorBlack);
	gotoxy(2 + player->x * 2, 1 + player->y);
	std::cout << "  ";
	player->x = startX;
	player->y = startY;
	player->Render();
	moveCount = 0;
	UpdateMoveCount();

}

void GameScene::UpdateMoveCount() {

	setBackgroundColor(ColorBlack);

	gotoxy(2, 43);
	std::cout << "이동 횟수 : " << moveCount << "          ";
	gotoxy(width + 12, starCntY + 2);
	if (moveCount <= starCutLine[0]) {
		std::cout << "★  ★  ★";
		starCount = 3;
	}
	else if (moveCount <= starCutLine[1]) {
		std::cout << "★  ★  ☆";
		starCount = 2;
	}
	else {
		std::cout << "★  ☆  ☆";
		starCount = 1;
	}

}

void GameScene::GameClear() {

	SceneManager::ChangeScene(new StageSelectScene(currentStage, starCount));
	return;

}