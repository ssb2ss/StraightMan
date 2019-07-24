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
	int GetGameData();			//�������� �����Ȳ (���� �����ϴ� ��������)
	int GetGameData(int stage);	//�� �������� �� ����

};