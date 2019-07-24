#pragma once
#include "IScene.h"

class MainScene :
	public IScene
{
public:
	MainScene();
	~MainScene();

	void Start();

	void PrintMainScene();
	void SelectMenu();
};