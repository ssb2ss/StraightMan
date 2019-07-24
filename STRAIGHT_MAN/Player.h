#pragma once
class Player
{
public:
	int x, y;

	Player();
	~Player();

	void Render();
	void Move(int destX, int destY);
};

