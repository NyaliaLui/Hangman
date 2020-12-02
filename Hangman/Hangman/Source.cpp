#include <iostream>
#include <string>

void draw(void) {
	// 9 x 10 grid
	std::string board[8];

	board[0] = "  ======= ";
	board[1] = "  |     | ";
	board[2] = "  |     O ";
	board[3] = "  |    /|\\";
	board[4] = "  |     | ";
	board[5] = "  |    / \\";
	board[6] = "  |       ";
	board[7] = "=====     ";

	std::cout << board[0] << std::endl;
	std::cout << board[1] << std::endl;
	std::cout << board[2] << std::endl;
	std::cout << board[3] << std::endl;
	std::cout << board[4] << std::endl;
	std::cout << board[5] << std::endl;
	std::cout << board[6] << std::endl;
	std::cout << board[7] << std::endl;
}

int main(void) {
	draw();
	return 0;
}