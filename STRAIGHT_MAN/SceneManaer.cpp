#include "SceneManager.h"
#include "MainScene.h"

IScene* SceneManager::nowScene = new MainScene();

SceneManager::SceneManager()
{
	InitGame();
	nowScene->Start();
}

SceneManager::~SceneManager()
{
	delete nowScene;
}

void SceneManager::InitGame() {
	setCursorType(CursorInvisible);
	setSize(160, 45);
	setTitle("STRAIGHT MAN");
}

void SceneManager::ChangeScene(IScene* newScene) {
	delete nowScene;
	system("cls");
	gotoxy(0, 0);
	nowScene = newScene;
	nowScene->Start();
}

void SceneManager::ExitGame() {
	system("cls");
	gotoxy(61, 22);
	exit(0);
}