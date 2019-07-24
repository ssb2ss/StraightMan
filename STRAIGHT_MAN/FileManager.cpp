#include "FileManager.h"
#include <string>

FileManager* FileManager::instance = nullptr;

FileManager::FileManager()
{
	
}

FileManager::~FileManager()
{

}

FileManager* FileManager::GetInstance() {
	if (instance == nullptr) {
		instance = new FileManager();
	}
	return instance;
}

void FileManager::SaveGame(GameData data) {

	std::ofstream fout;

	fout.open("StraightManData");

	fout << data.stage << std::endl;

	for (int i = 0; i < 24; i++) {
		fout << data.starCount[i] << std::endl;
	}

	fout.close();

}

int FileManager::GetGameData() {

	//스테이지 진행상황 (현재 깨야하는 스테이지)

	int stage;
	std::string in_line;

	std::ifstream fin;

	fin.open("StraightManData");
	if (fin.fail()) {
		return 1;
	}

	fin >> in_line;
	stage = atoi(in_line.c_str());

	fin.close();

	return stage;

}

int FileManager::GetGameData(int stage) {

	//각 스테이지 별 개수

	int starCount;
	std::string in_line[25];

	std::ifstream fin;

	fin.open("StraightManData");
	if (fin.fail()) {
		return 0;
	}

	for (int i = 0; i < 25; i++) {
		fin >> in_line[i];
	}

	starCount = atoi(in_line[stage].c_str());

	fin.close();

	return starCount;

}