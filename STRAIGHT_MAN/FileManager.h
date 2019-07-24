#pragma once
#include <fstream>

class FileManager
{
private:
	FileManager();
	~FileManager();

	static FileManager* instance;
public:
	static FileManager* GetInstance();

	typedef struct _GameData {
		int stage;
		int starCount[24];
	}GameData;

	void SaveGame(GameData data);
	int GetGameData();			//스테이지 진행상황 (현재 깨야하는 스테이지)
	int GetGameData(int stage);	//각 스테이지 별 개수

};