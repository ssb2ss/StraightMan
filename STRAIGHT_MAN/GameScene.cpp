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
			starCutLine[1] = 15;
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
		case 2:
			starCutLine[0] = 14;
			starCutLine[1] = 16;
			mapArray[0]  = "111111111111111111111111111111111111111111111111111111";
			mapArray[1]  = "120000100000000000000000000000000000000000000000000001";
			mapArray[2]  = "100000100000000000000000000000000000000000000000000001";
			mapArray[3]  = "100000100000000000000000000000000000000000000000000001";
			mapArray[4]  = "100000100000000000000000000000000000000000000000000001";
			mapArray[5]  = "100000100000000000000000000000000000000000000000000001";
			mapArray[6]  = "100000100000111111111111111111111111111111111111000001";
			mapArray[7]  = "100000100000100000000000000000000000000000000001000001";
			mapArray[8]  = "100000100000100000000000000000000000000000000001000001";
			mapArray[9]  = "100000100000100000000000000000000000000000000001000001";
			mapArray[10] = "100000100000100000000000000000000000000000000001000001";
			mapArray[11] = "100000100000100000000000000000000000000000000001000001";
			mapArray[12] = "100000100000100000111111111111111111111111000001000001";
			mapArray[13] = "100000100000100000100000000000000000000001000001000001";
			mapArray[14] = "100000100000100000100000000000000000000001000001000001";
			mapArray[15] = "100000100000100000100000000000000000000001000001000001";
			mapArray[16] = "100000100000100000100000000000000000000001000001000001";
			mapArray[17] = "100000100000100000100000000000000000000001000001000001";
			mapArray[18] = "100000100000100000100000000000000001000001000001000001";
			mapArray[19] = "100000100000100000100000000000000001000001000001000001";
			mapArray[20] = "100000100000100000100000000000000001000001000001000001";
			mapArray[21] = "100000100000100000100000000000000031000001000001000001";
			mapArray[22] = "100000100000100000111111111111111111000001000001000001";
			mapArray[23] = "100000100000100000000000000000000000000001000001000001";
			mapArray[24] = "100000100000100000000000000000000000000001000001000001";
			mapArray[25] = "100000100000100000000000000000000000000001000001000001";
			mapArray[26] = "100000100000100000000000000000000000000001000001000001";
			mapArray[27] = "100000100000100000000000000000000000000001000001000001";
			mapArray[28] = "100000100000111111111111111111111111111111000001000001";
			mapArray[29] = "100000100000000000000000000000000000000000000001000001";
			mapArray[30] = "100000100000000000000000000000000000000000000001000001";
			mapArray[31] = "100000100000000000000000000000000000000000000001000001";
			mapArray[32] = "100000100000000000000000000000000000000000000001000001";
			mapArray[33] = "100000100000000000000000000000000000000000000001000001";
			mapArray[34] = "100000111111111111111111111111111111111111111111000001";
			mapArray[35] = "100000000000000000000000000000000000000000000000000001";
			mapArray[36] = "100000000000000000000000000000000000000000000000000001";
			mapArray[37] = "100000000000000000000000000000000000000000000000000001";
			mapArray[38] = "100000000000000000000000000000000000000000000000000001";
			mapArray[39] = "100000000000000000000000000000000000000000000000000001";
			mapArray[40] = "111111111111111111111111111111111111111111111111111111";
			break;
		case 3:
			starCutLine[0] = 12;
			starCutLine[1] = 15;
			mapArray[0]  = "111111111111111111111111111111111111111111111111111111";
			mapArray[1]  = "120000000000000000000000001100000000000000000000000001";
			mapArray[2]  = "100000000000000000000000001100000000000000000000000001";
			mapArray[3]  = "100000000000000000000000000000000000000000000000000001";
			mapArray[4]  = "111111111000000000000000000000000000000000000111111111";
			mapArray[5]  = "100000000000000000000000000000000000000000000000000001";
			mapArray[6]  = "100000000000000000000000000000000000000000000000000001";
			mapArray[7]  = "100000000000000000000000000000000000000000000000000001";
			mapArray[8]  = "100000000000000000000000000000000000000000000000000001";
			mapArray[9]  = "100000000000000000000000000000000000000000000000000001";
			mapArray[10] = "100000000000000000000000000000000000000000000000000001";
			mapArray[11] = "100000000000000000000000001111000000000000000000000001";
			mapArray[12] = "100000000000000000000000000000000000000000000000000001";
			mapArray[13] = "100000000000000000000000000000000000000000000000000001";
			mapArray[14] = "100000000000000000000000000000000000000000000000000001";
			mapArray[15] = "100000000000000000000000000000000000000000000000000001";
			mapArray[16] = "100000000000000000000000000000000000000000000000000001";
			mapArray[17] = "100000000000000000000000000000000000000000000000000001";
			mapArray[18] = "100000010000000000000000000000000000000000000000000001";
			mapArray[19] = "100000010000000000000000000000000000000000000000000001";
			mapArray[20] = "100000011111111111111111111111111111111111111111111111";
			mapArray[21] = "100000000000000000000000000000000000000000000000000001";
			mapArray[22] = "100000000000000000000000000000000000000000000000000001";
			mapArray[23] = "100000000000000000000000000000000000000000000000000001";
			mapArray[24] = "100000000000000000000000000000000000000000000000000001";
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
			mapArray[36] = "100000000000000000000000000000000000000000000000000001";
			mapArray[37] = "100000000000000000000000000000000000000000000000000001";
			mapArray[38] = "100000000000000000000000001100000000000000000000000001";
			mapArray[39] = "130000000000000000000000001100000000000000000000000001";
			mapArray[40] = "111111111111111111111111111111111111111111111111111111";
			break;
		case 4:
			starCutLine[0] = 16;
			starCutLine[1] = 18;
			mapArray[0]  = "111111111111111111111111111111111111111111111111111111";
			mapArray[1]  = "100000000000000000000000103010000000000000000000000001";
			mapArray[2]  = "100000000000000000000000100010000000000000000000000001";
			mapArray[3]  = "100000000000000000000000000000000000000000000000000001";
			mapArray[4]  = "100000000000000000000000000000000000000000000000000001";
			mapArray[5]  = "100000000000000000000000000000000000000000000000000001";
			mapArray[6]  = "100000000000000000000000000000000000000000000000000001";
			mapArray[7]  = "100001111111111111111111110111111111111111111111100001";
			mapArray[8]  = "100001000010000000000000000000000000000000000000100001";
			mapArray[9]  = "100001000010000000000000000000000000000000000000100001";
			mapArray[10] = "100001000000000000000000000000000000000000000000100001";
			mapArray[11] = "111001000000000000000000000000000000000000000000100001";
			mapArray[12] = "100001000010111111111111110111111111111111110000100001";
			mapArray[13] = "100001000010000000000000000000000000000000010000100001";
			mapArray[14] = "100001000010000000000000000000000000000000010000100001";
			mapArray[15] = "100001000010000000000000000000000000000000010000100001";
			mapArray[16] = "100001000010000000000000000000000000000000010000100001";
			mapArray[17] = "100001000010000111111111110111111111111000010000100001";
			mapArray[18] = "100001000010000100000000000000000000001000010000100001";
			mapArray[19] = "100001000011100100000000000000000000000000010000100001";
			mapArray[20] = "100001000010000100000000000000000000000001110000100001";
			mapArray[21] = "100001000010000100000000000000000000000000010000100001";
			mapArray[22] = "100001000010000100000000000100000000001000010000100001";
			mapArray[23] = "100001000010011111111111111111111111111000010000100001";
			mapArray[24] = "100001000010000000000000000000000000000000010000100001";
			mapArray[25] = "100001000010000000000000000000000000000000010000100001";
			mapArray[26] = "100001000010000000000000000000000000000000010000100001";
			mapArray[27] = "100001000010000000000000000000000000000000010000100001";
			mapArray[28] = "100001000011111111111111111111111111111111110000100001";
			mapArray[29] = "100001000000000000000000000000000000000000000000100001";
			mapArray[30] = "100001000000000000000000000000000000000000000000100001";
			mapArray[31] = "100001000000000000000000000000000000000000000000100001";
			mapArray[32] = "100000000000000000000000000000000000000000000000100001";
			mapArray[33] = "100111111111111111111111111111111111111111111111100001";
			mapArray[34] = "100000000000000000000000000000000000000000000000000001";
			mapArray[35] = "100000000000000000000000000000000000000000000000000001";
			mapArray[36] = "100000000000000000000000000000000000000000000000000001";
			mapArray[37] = "100000000000000000000000000000000000000000000000000001";
			mapArray[38] = "100000000000000000000000000000000000000000000000000001";
			mapArray[39] = "100000000000000000000000002000000000000000000000000001";
			mapArray[40] = "111111111111111111111111111111111111111111111111111111";
			break;
		case 5:
			starCutLine[0] = 49;
			starCutLine[1] = 51;
			mapArray[0]  = "111111111111111111111111111111111111111111111111111111";
			mapArray[1]  = "130000000000000000000000000000000000000000000000000001";
			mapArray[2]  = "111111111111111111111111111111111111111111111111111101";
			mapArray[3]  = "111111111111111111111111111111111111111111111111111101";
			mapArray[4]  = "111111111111111111111111111111110000011111111111111101";
			mapArray[5]  = "111111111000000100000000000111110001011111111111111101";
			mapArray[6]  = "111111111011110101111111110111110001011111111111111101";
			mapArray[7]  = "111111111011110000011111110110000101011111111111111101";
			mapArray[8]  = "111111111011111101011111110100010001000000000000000001";
			mapArray[9]  = "111111111000000001000001110101111111111111111111111111";
			mapArray[10] = "111111111111111111011101110101111111111111111111111111";
			mapArray[11] = "111111111111111000000101110001111111111111111111111111";
			mapArray[12] = "111111111111111011110101111111111111111111111111111111";
			mapArray[13] = "111111111111111001110101111111111111111111111111111111";
			mapArray[14] = "111111111111111101110001111111111111111111111111111111";
			mapArray[15] = "100000000000000001111111111111111111111111111111111111";
			mapArray[16] = "101111111111111111111111111111111111111111111111111111";
			mapArray[17] = "101111111111111111111111100000000000000000000000000001";
			mapArray[18] = "101111111111111111111111101111111111111111111111111101";
			mapArray[19] = "101111111111111111111111101111111111111111111111111101";
			mapArray[20] = "101111111111111111111111101111111111111111111111111101";
			mapArray[21] = "101111111111111111111111101111111111111111111111111101";
			mapArray[22] = "101111111111111111111111101111111111111111111111111101";
			mapArray[23] = "101111111111111111111111101111111111111111111111111101";
			mapArray[24] = "101111111111111111111111101111111111111111111111111101";
			mapArray[25] = "101111111111111111111111101111111111111111111111111101";
			mapArray[26] = "101111111111111111111111101111111111111111111111111101";
			mapArray[27] = "101111111111111111111111101111111111111111000011111101";
			mapArray[28] = "101111111111111111111111101111111111111111000011111101";
			mapArray[29] = "101111111111111111111111101111111111111111000011111101";
			mapArray[30] = "101111111111111111111111101111111111111111011000000001";
			mapArray[31] = "100000000000000000000000001111111111111111000001111111";
			mapArray[32] = "111111111111111111111111111111111111111111111101111111";
			mapArray[33] = "100011111111111111111111111000111111111111111001111111";
			mapArray[34] = "100011111111111111111111111010111111111111111011111111";
			mapArray[35] = "100000000000000000000000000010000000000000000011111111";
			mapArray[36] = "111011111111111111111111111111111111111111111111111111";
			mapArray[37] = "100011111111111111111111111111111111111111111111100001";
			mapArray[38] = "101111111111111111111111111111111111111111111111100001";
			mapArray[39] = "100000000000000000000000000000000000000000000000000021";
			mapArray[40] = "111111111111111111111111111111111111111111111111111111";
			break;
		case 6:
			starCutLine[0] = 60;
			starCutLine[1] = 66;
			mapArray[0]  = "111111111111111111111111111111111111111111111111111111";
			mapArray[1]  = "100000000000001000000000000111000000000000000000000001";
			mapArray[2]  = "100000000000000000000000000001011111111011110000000001";
			mapArray[3]  = "100000000000010000000000000101011111111010100010000001";
			mapArray[4]  = "100000000000000000000000000101000000000010100000000101";
			mapArray[5]  = "100000000000000000000000000101111111111010100000000001";
			mapArray[6]  = "100000000000000000000000000101111111111000100000000001";
			mapArray[7]  = "100000000000000000000000000101111111111110100000100001";
			mapArray[8]  = "100000000000000000000000000101111111111110100000000011";
			mapArray[9]  = "100000000000000000000000000101111111111110100100000001";
			mapArray[10] = "100000000000000000000000000101111111111110100000010001";
			mapArray[11] = "100000000000000000000000000101111111111110100000000001";
			mapArray[12] = "100000000000000000000000000101111111111110100000010101";
			mapArray[13] = "100000000000000000000000000101111111111110101000000001";
			mapArray[14] = "100000000000000000000000000101111111111110111111101111";
			mapArray[15] = "100000000000000000000000000101111111111110100000000001";
			mapArray[16] = "100000000000000000000000000101111111111110101111101101";
			mapArray[17] = "101000000000000000000000000101111111111110101000001101";
			mapArray[18] = "100000000000000000000000010000000000000000101011111101";
			mapArray[19] = "100000000000000000000000000131111111111111101000001101";
			mapArray[20] = "100000000000000000000000000111111111111000101111101101";
			mapArray[21] = "100000000000000000000000000111111111111010100000001101";
			mapArray[22] = "100000000000000000000000000111111111111010111111111101";
			mapArray[23] = "100000000000000000000000000111000000000000000000000001";
			mapArray[24] = "100000000000000000000000000111111111111100111111111111";
			mapArray[25] = "100000000000000000000000000111111111111100100000000001";
			mapArray[26] = "100000000000000000000000000111000000000000100111111101";
			mapArray[27] = "100000000000000000000000000111111011111111100100000001";
			mapArray[28] = "100000000000000000000000000111111010000111100101000001";
			mapArray[29] = "100000000000000000000000000111111010110111110101011111";
			mapArray[30] = "100000000001000000000000000111111010110111100101000001";
			mapArray[31] = "100000000000000000000000001111111010000000100101001001";
			mapArray[32] = "100000000000000000000100000111111011110110100100000001";
			mapArray[33] = "100000000000000000000000000111111011110110100111110111";
			mapArray[34] = "100000000000000000000000000111111010000000101111000111";
			mapArray[35] = "100000000000000000000000000111111010110111100111011111";
			mapArray[36] = "100000000000000000000000000111111010110111100111000001";
			mapArray[37] = "100000000000000000000000000111111010000000100111000001";
			mapArray[38] = "110000000000000000000000001111111011110100100111000001";
			mapArray[39] = "110000000000000100000000001111111000000100000111000021";
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
	gotoxy(width + 12, 5);
	std::cout << "  ";
	setBackgroundColor(ColorBlack);
	std::cout << " : 플레이어";
	setBackgroundColor(ColorLightBlue);
	gotoxy(width + 12, 7);
	std::cout << "  ";
	setBackgroundColor(ColorBlack);
	std::cout << " : 목적지";
	gotoxy(width + 12, 11);
	std::cout << "방향키 (WASD) : 이동";
	gotoxy(width + 12, 13);
	std::cout << "R : 재시작";
	gotoxy(width + 12, 15);
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