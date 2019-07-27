#pragma once
#include "IScene.h"
#include "ConsoleFunctions.h"

class StageSelectScene :
	public IScene
{
public:
	int stageWidth, stageHeight;
	int playableStage;
	int stageStar[18];
	int selectedStage;

	StageSelectScene();
	StageSelectScene(int stage, int star);
	~StageSelectScene();

	void Start();

	void LoadData();
	void SaveData();
	void UpdateData(int stage, int star);
	void PrintSelectScene();
	void PrintStage(int x, int y, int stage, bool isPlayable, int starCount);
	void SelectStage();
	void PrintStageBorder(int x, int y, Color color);
};