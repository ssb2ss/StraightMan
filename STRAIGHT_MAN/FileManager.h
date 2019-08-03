#pragma once
#include <fstream>

typedef struct _GameData {
	int stage;
	int starCount[24];
}GameData;

class FileManager
{
private:
	FileManager();
	~FileManager();

	static FileManager* instance;
public:
	static FileManager* GetInstance();

	void SaveGame(GameData data);
	int GetGameData();			//�������� �����Ȳ (���� �����ϴ� ��������)
	int GetGameData(int stage);	//�� �������� �� ����

};

