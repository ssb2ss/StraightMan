#include "StageSelectScene.h"
#include "SceneManager.h"
#include "FileManager.h"

#include "MainScene.h"
#include "GameScene.h"

StageSelectScene::StageSelectScene()
{
	selectedStage = 1;
}

StageSelectScene::StageSelectScene(int stage, int star) 
{
	UpdateData(stage, star);
	selectedStage = stage;
}

StageSelectScene::~StageSelectScene()
{

}

void StageSelectScene::Start() {
	stageWidth = 22;
	stageHeight = 9;

	LoadData();
	SaveData();

	PrintSelectScene();
	SelectStage();
}

void StageSelectScene::LoadData() {

	playableStage = FileManager::GetInstance()->GetGameData();
	for (int i = 0; i < 18; i++) {
		stageStar[i] = FileManager::GetInstance()->GetGameData(i + 1);
	}

}

void StageSelectScene::SaveData() {

	FileManager::GameData data;
	data.stage = playableStage;
	for (int i = 0; i < 18; i++) {
		data.starCount[i] = stageStar[i];
	}
	FileManager::GetInstance()->SaveGame(data);

}

void StageSelectScene::UpdateData(int stage, int star) {

	LoadData();
	if (playableStage < stage + 1) {
		playableStage = stage + 1;
	}
	if (stageStar[stage - 1] < star) {
		stageStar[stage - 1] = star;
	}
	SaveData();

}

void StageSelectScene::PrintSelectScene() {

	int cnt = 0;
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 6; j++) {
			PrintStage((26 * j) + 4, (11 * i) + 1, cnt + 1, playableStage > cnt, stageStar[cnt]);
			cnt++;
		}
	}

	Color temp;
	if (playableStage >= 19) {
		temp = ColorWhite;
	}
	else {
		temp = ColorGray;
	}

	for (int i = 0; i < stageHeight; i++) {
		for (int j = 0; j < stageWidth * 6 + 20; j++) {
			if (i == 0 || i == stageHeight - 1 || (j == 0 || j == 1) || (j == (stageWidth * 6 + 20) - 2 || j == (stageWidth * 6 + 20) - 1)) {
				setBackgroundColor(temp);
				gotoxy(4 + j, 34 + i);
				std::cout << " ";
			}
		}
	}

	setBackgroundColor(ColorBlack);
	gotoxy(78, 38);
	std::cout << "엔딩";

}

void StageSelectScene::PrintStage(int x, int y, int stage, bool isPlayable, int starCount) {

	Color temp;
	if (isPlayable) {
		temp = ColorWhite;
	}
	else {
		temp = ColorGray;
	}
	PrintStageBorder(x, y, temp);

	setBackgroundColor(ColorBlack);

	gotoxy(x + (stageWidth - 2) / 2, y + (stageHeight / 2));
	std::cout << stage;

	gotoxy(x + (stageWidth - 2) / 2 - 4, y + stageHeight - 2);
	if (starCount == 0) {
		std::cout << "☆  ☆  ☆";
	}
	else if (starCount == 1) {
		std::cout << "★  ☆  ☆";
	}
	else if (starCount == 2) {
		std::cout << "★  ★  ☆";
	}
	else if (starCount == 3) {
		std::cout << "★  ★  ★";
	}

	gotoxy(0, 44);
	std::cout << "방향키 (WASD) : 이동 | 스페이스바 : 선택 | ESC : 메인화면";

	int totalStar = 0;
	for (int i = 0; i < 18; i++) {
		totalStar += stageStar[i];
	}

	if (totalStar / 10 == 0) {
		gotoxy(137, 44);
	}
	else {
		gotoxy(136, 44);
	}
	std::cout << "모은 별의 개수 : " << totalStar << " / 54";

}

void StageSelectScene::SelectStage() {

	int x, y;
	x = 26 * ((selectedStage - 1) % 6) + 4;
	y = 11 * ((selectedStage - 1) / 6) + 1;

	PrintStageBorder(x, y, ColorLightRed);

	while (true) {
		if (_kbhit()) {
			char key = _getch();
			if (key == 27) { //ESC
				setBackgroundColor(ColorBlack);
				SceneManager::ChangeScene(new MainScene());
				break;
			}
			else if (key == 32) { //스페이스바
				setBackgroundColor(ColorBlack);
				if (selectedStage == 19) {
					//게임엔딩
					break;
				}
				else {
					SceneManager::ChangeScene(new GameScene(selectedStage));
					break;
				}
			}
			else if (key == 75 || key == 'A' || key == 'a') { //왼쪽
				if (selectedStage == 19) {
					for (int i = 0; i < stageHeight; i++) {
						for (int j = 0; j < stageWidth * 6 + 20; j++) {
							if (i == 0 || i == stageHeight - 1 || (j == 0 || j == 1) || (j == (stageWidth * 6 + 20) - 2 || j == (stageWidth * 6 + 20) - 1)) {
								setBackgroundColor(ColorWhite);
								gotoxy(4 + j, 34 + i);
								std::cout << " ";
							}
						}
					}
					selectedStage = 18;
					x = 26 * ((selectedStage - 1) % 6) + 4;
					y = 11 * ((selectedStage - 1) / 6) + 1;
					PrintStageBorder(x, y, ColorLightRed);
				}
				else if (selectedStage > 1) {
					PrintStageBorder(x, y, ColorWhite);
					selectedStage--;
					x = 26 * ((selectedStage - 1) % 6) + 4;
					y = 11 * ((selectedStage - 1) / 6) + 1;
					PrintStageBorder(x, y, ColorLightRed);
				}
			}
			else if ((key == 77 || key == 'D' || key == 'd') && (selectedStage < playableStage)) { //오른쪽
				if (selectedStage < 18) {
					PrintStageBorder(x, y, ColorWhite);
					selectedStage++;
					x = 26 * ((selectedStage - 1) % 6) + 4;
					y = 11 * ((selectedStage - 1) / 6) + 1;
					PrintStageBorder(x, y, ColorLightRed);
				}
				else if (selectedStage == 18) {
					PrintStageBorder(x, y, ColorWhite);
					selectedStage = 19;
					for (int i = 0; i < stageHeight; i++) {
						for (int j = 0; j < stageWidth * 6 + 20; j++) {
							if (i == 0 || i == stageHeight - 1 || (j == 0 || j == 1) || (j == (stageWidth * 6 + 20) - 2 || j == (stageWidth * 6 + 20) - 1)) {
								setBackgroundColor(ColorLightRed);
								gotoxy(4 + j, 34 + i);
								std::cout << " ";
							}
						}
					}
				}
			}
			else if (key == 72 || key == 'W' || key == 'w') { //위쪽
				if (selectedStage == 19) {
					for (int i = 0; i < stageHeight; i++) {
						for (int j = 0; j < stageWidth * 6 + 20; j++) {
							if (i == 0 || i == stageHeight - 1 || (j == 0 || j == 1) || (j == (stageWidth * 6 + 20) - 2 || j == (stageWidth * 6 + 20) - 1)) {
								setBackgroundColor(ColorWhite);
								gotoxy(4 + j, 34 + i);
								std::cout << " ";
							}
						}
					}
					selectedStage = 18;
					x = 26 * ((selectedStage - 1) % 6) + 4;
					y = 11 * ((selectedStage - 1) / 6) + 1;
					PrintStageBorder(x, y, ColorLightRed);
				}
				else if (selectedStage > 6) {
					PrintStageBorder(x, y, ColorWhite);
					selectedStage -= 6;
					x = 26 * ((selectedStage - 1) % 6) + 4;
					y = 11 * ((selectedStage - 1) / 6) + 1;
					PrintStageBorder(x, y, ColorLightRed);
				}
			}
			else if ((key == 80 || key == 'S' || key == 's') && (selectedStage + 5 < playableStage || playableStage == 19)) { //아래쪽
				if (selectedStage < 13) {
					PrintStageBorder(x, y, ColorWhite);
					selectedStage += 6;
					x = 26 * ((selectedStage - 1) % 6) + 4;
					y = 11 * ((selectedStage - 1) / 6) + 1;
					PrintStageBorder(x, y, ColorLightRed);
				}
				else if (selectedStage < 19) {
					PrintStageBorder(x, y, ColorWhite);
					selectedStage = 19;
					for (int i = 0; i < stageHeight; i++) {
						for (int j = 0; j < stageWidth * 6 + 20; j++) {
							if (i == 0 || i == stageHeight - 1 || (j == 0 || j == 1) || (j == (stageWidth * 6 + 20) - 2 || j == (stageWidth * 6 + 20) - 1)) {
								setBackgroundColor(ColorLightRed);
								gotoxy(4 + j, 34 + i);
								std::cout << " ";
							}
						}
					}
				}
			}
		}
	}
}

void StageSelectScene::PrintStageBorder(int x, int y, Color color) {
	for (int i = 0; i < stageHeight; i++) {
		for (int j = 0; j < stageWidth; j++) {
			if (i == 0 || i == stageHeight - 1 || (j == 0 || j == 1) || (j == stageWidth - 2 || j == stageWidth - 1)) {
				setBackgroundColor(color);
				gotoxy(x + j, y + i);
				std::cout << " ";
			}
		}
	}
}