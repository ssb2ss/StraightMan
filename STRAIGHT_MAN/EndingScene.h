#pragma once
#include "IScene.h"
#include <string>
class EndingScene :
	public IScene
{
public:
	int star;
	std::string logoArray[45];

	EndingScene(int star);
	~EndingScene();

	void Start();

	void PrintClearLogo();
	void PrintMessage();
	void SelectMenu();
};