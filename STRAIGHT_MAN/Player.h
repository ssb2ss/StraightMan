#pragma once
class Player
{
public:
	int x, y;
	int moveTime;

	Player();
	~Player();

	void Render();
	void Move(int destX, int destY);
};

