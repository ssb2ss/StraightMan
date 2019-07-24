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

	std::string mapArray[41]; // 0 : 빈공간 / 1 : 벽 / 2 : 플레이어 / 3 : 목적지
	Player* player;
	int moveCount;
	int startX, startY;
	int goalX, goalY;

	GameScene(int stage);
	~GameScene();

	void Start();

	void SetMap();
	void PrintMap();
	void PlayGame();
	void RestartGame();
	void UpdateMoveCount();
	void GameClear();
};

