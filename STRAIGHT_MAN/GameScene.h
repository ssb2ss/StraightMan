#pragma once
#include "IScene.h"
#include "Player.h"
#include <string>

class GameScene :
	public IScene
{
public:
	int currentStage;
	int width, height;
	int starCntY;

	std::string mapArray[41]; // 0 : ����� / 1 : �� / 2 : �÷��̾� / 3 : ������
	int starCutLine[2]; //[0] : �� 3�� ĿƮ���� / [1] : �� 2�� ĿƮ����
	Player* player;
	int moveCount;
	int starCount;
	int startX, startY;
	int goalX, goalY;

	GameScene(int stage);
	~GameScene();

	void Start();

	void SetMap();
	void PrintMap();
	void PrintStar();
	void PlayGame();
	void RestartGame();
	void UpdateMoveCount();
	void GameClear();
};

