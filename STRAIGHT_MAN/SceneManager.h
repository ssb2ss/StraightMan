#pragma once
#include "IScene.h"
#include "ConsoleFunctions.h"
#include <iostream>

class SceneManager
{
public:
	static IScene* nowScene;

	SceneManager();
	~SceneManager();

	void InitGame();
	void static ChangeScene(IScene* newScene);
	void static ExitGame();
};