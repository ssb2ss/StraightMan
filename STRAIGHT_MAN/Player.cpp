#include "Player.h"
#include "ConsoleFunctions.h"

Player::Player()
{
	moveTime = 60;
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

	if (x != destX) {
		if (x > destX) {
			setBackgroundColor(ColorLightRed);
			for (int i = x; i >= destX; i--) {
				gotoxy(2 + i * 2, 1 + y);
				std::cout << "  ";
			}
			Sleep(moveTime);
			int diff = x - destX;
			setBackgroundColor(ColorBlack);
			for (int i = x; i > destX; i--) {
				gotoxy(2 + i * 2, 1 + y);
				std::cout << "  ";
				Sleep(moveTime / diff);
			}
		}
		else {
			setBackgroundColor(ColorLightRed);
			for (int i = x; i <= destX; i++) {
				gotoxy(2 + i * 2, 1 + y);
				std::cout << "  ";
			}
			Sleep(moveTime);
			int diff = destX - x;
			setBackgroundColor(ColorBlack);
			for (int i = x; i < destX; i++) {
				gotoxy(2 + i * 2, 1 + y);
				std::cout << "  ";
				Sleep(moveTime / diff);
			}
		}
	}
	else if (y != destY) {
		if (y > destY) {
			setBackgroundColor(ColorLightRed);
			for (int i = y; i >= destY; i--) {
				gotoxy(2 + x * 2, 1 + i);
				std::cout << "  ";
			}
			Sleep(moveTime);
			int diff = y - destY;
			setBackgroundColor(ColorBlack);
			for (int i = y; i > destY; i--) {
				gotoxy(2 + x * 2, 1 + i);
				std::cout << "  ";
				Sleep(moveTime / diff);
			}
		}
		else {
			setBackgroundColor(ColorLightRed);
			for (int i = y; i <= destY; i++) {
				gotoxy(2 + x * 2, 1 + i);
				std::cout << "  ";
			}
			Sleep(moveTime);
			int diff = destY - y;
			setBackgroundColor(ColorBlack);
			for (int i = y; i < destY; i++) {
				gotoxy(2 + x * 2, 1 + i);
				std::cout << "  ";
				Sleep(moveTime / diff);
			}
		}
	}

	while (_kbhit()) {	//
		_getch();		// 버퍼 초기화
	}					//

	x = destX;
	y = destY;

	setBackgroundColor(ColorBlack);

}