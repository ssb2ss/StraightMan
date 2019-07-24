#include "Player.h"
#include "ConsoleFunctions.h"

Player::Player()
{

}

Player::~Player()
{

}

void Player::Render() {
	setBackgroundColor(ColorLightRed);
	gotoxy(2 + x * 2, 1 + y);
	std::cout << "  ";
	setBackgroundColor(ColorBlack);
}

void Player::Move(int destX, int destY) {
	
	setBackgroundColor(ColorBlack);
	gotoxy(2 + x * 2, 1 + y);
	std::cout << "  ";

	x = destX;
	y = destY;

	setBackgroundColor(ColorLightRed);
	gotoxy(2 + x * 2, 1 + y);
	std::cout << "  ";

	setBackgroundColor(ColorBlack);

}