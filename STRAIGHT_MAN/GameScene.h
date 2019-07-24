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

	std::string mapArray[41]; // 0 : 빈공간 / 1 : 벽 / 2 : 플레이어 / 3 : 목적지
	int starCutLine[2]; //[0] : 별 3개 커트라인 / [1] : 별 2개 커트라인
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

