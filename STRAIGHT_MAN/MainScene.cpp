#include "MainScene.h"
#include "SceneManager.h"

#include "StageSelectScene.h"

MainScene::MainScene()
{

}

MainScene::~MainScene()
{

}

void MainScene::Start() {
	PrintMainScene();
	SelectMenu();
}

void MainScene::PrintMainScene() {

	setBackgroundColor(ColorWhite);
	for (int y = 0; y < 10; y++) {
		for (int x = 0; x < 42; x++) {
			gotoxy((x * 2) + 38, y + 10);
			switch (y) {
				case 0:
					std::cout << "  ";
					break;
				case 1:
					if (x == 0)
						std::cout << "  ";
					break;
				case 2:
					if (x == 0 || x == 9 || x == 24)
						std::cout << "  ";
					break;
				case 3:
					if ((x >= 0 && x <= 5) || (x >= 9 && x <= 10) || (x >= 15 && x <= 18) || (x >= 23 && x <= 25) || (x >= 32 && x <= 35))
						std::cout << "  ";
					break;
				case 4:
				case 5:
					if (x == 5 || x == 9 || x == 15 || x == 18 || x == 24 || x == 32 || x == 35)
						std::cout << "  ";
					break;
				case 6:
					if ((x >= 0 && x <= 5) || x == 9 || (x >= 15 && x <= 18) || (x >= 24 && x <= 25) || (x >= 32 && x <= 35))
						std::cout << "  ";
					break;
				case 7:
					if (x == 18 || (x >= 35 && x <= 36))
						std::cout << "  ";
					break;
				case 8:
					if (x == 18)
						std::cout << "  ";
					break;
				case 9:
					if (x >= 15 && x <= 18)
						std::cout << "  ";
					break;
			}
		}
	}

	setBackgroundColor(ColorGray);
	for (int y = 0; y < 10; y++) {
		for (int x = 0; x < 42; x++) {
			gotoxy((x * 2) + 38, y + 10);
			switch (y) {
				case 0:
					break;
				case 1:
					if (x == 19)
						std::cout << "  ";
					break;
				case 2:
					if (x == 7 || x == 19)
						std::cout << "  ";
					break;
				case 3:
					if ((x >= 6 && x <= 8) || (x >= 11 && x <= 14) || (x >= 19 && x <= 22) || (x >= 27 && x <= 31) || (x >= 36 && x <= 39))
						std::cout << "  ";
					break;
				case 4:
				case 5:
					if (x == 7 || x == 11 || x == 14 || x == 19 || x == 22 || x == 27 || x == 29 || x == 31 || x == 36 || x == 39)
						std::cout << "  ";
					break;
				case 6:
					if ((x >= 7 && x <= 8) || (x >= 11 && x <= 14) || x == 19 || x == 22 || x == 27 || x == 29 || x == 31 || x == 36 || x == 39)
						std::cout << "  ";
					break;
				case 7:
					if (x == 14 || x == 15)
						std::cout << "  ";
					break;
			}
		}
	}

	setBackgroundColor(ColorBlack);

	gotoxy(76, 28);
	std::cout << "게임시작";
	gotoxy(78, 31);
	std::cout << "종료";
	gotoxy(0, 0);
	std::cout << "20626 홍성목";
	gotoxy(0, 44);
	std::cout << "방향키 (WASD) : 이동 | 스페이스바 : 선택";

}

void MainScene::SelectMenu() {

	int currentSelect = 0;

	gotoxy(72, 28);
	std::cout << ">>";

	while (true) {
		if (_kbhit()) {
			char key = _getch();
			if (key == 32) { //스페이스바
				if (currentSelect == 0) {
					//게임시작
					SceneManager::ChangeScene(new StageSelectScene());
					break;
				}
				else {
					//종료
					SceneManager::ExitGame();
					break;
				}
			}
			else if (key == 72 || key == 'w' || key == 'W') { //위 방향키
				if (currentSelect == 1) {
					currentSelect = 0;
					gotoxy(74, 31);
					std::cout << "  ";
					gotoxy(72, 28);
					std::cout << ">>";
				}
			}
			else if (key == 80 || key == 's' || key == 'S') {
				if (currentSelect == 0) {
					currentSelect = 1;
					gotoxy(72, 28);
					std::cout << "  ";
					gotoxy(74, 31);
					std::cout << ">>";
				}
			}
		}
	}

}