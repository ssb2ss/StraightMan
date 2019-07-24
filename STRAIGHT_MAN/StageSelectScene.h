#pragma once
#include "IScene.h"
#include "ConsoleFunctions.h"

class StageSelectScene :
	public IScene
{
public:
	int stageWidth, stageHeight;
	bool playableStage[24];
	int stageStar[24];

	StageSelectScene();
	~StageSelectScene();

	void Start();

	void PrintSelectScene();
	void PrintStage(int x, int y, int stage, bool isPlayable, int starCount);
	void SelectStage();
	void PrintStageBorder(int x, int y, Color color);
};