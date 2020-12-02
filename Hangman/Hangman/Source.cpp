#include <iostream>
#include <algorithm>
#include "GameCLI.h"

void draw(void) {
	std::string word("Nyalia is Amazing");
	std::string fill_space(word);
	for (size_t i = 0; i < word.length(); ++i) {
		if (word[i] != ' ') {
			fill_space[i] = '_';
		}
	}

	std::string board[9];

	board[0] = "  ======= ";
	board[1] = "  |     |    ";
	board[2] = "  |     O    ";
	board[3] = "  |    /|\\   ";
	board[4] = "  |     |    ";
	board[5] = "  |    / \\   ";
	board[6] = "  |          ";
	board[7] = "=====     ";
	board[8] = "      ";
	board[8] = board[8] + fill_space;

	std::cout << board[0] << std::endl;
	std::cout << board[1] << std::endl;
	std::cout << board[2] << std::endl;
	std::cout << board[3] << std::endl;
	std::cout << board[4] << std::endl;
	std::cout << board[5] << std::endl;
	std::cout << board[6] << std::endl;
	std::cout << board[7] << std::endl;
	std::cout << board[8] << std::endl << std::endl;;

	char _alphabet[26];
	for (size_t i = 0; i < 26; ++i) {
		_alphabet[i] = '-';
	}

	board[1] = board[1] + _alphabet[0] + ' ' + _alphabet[1] + ' ' + _alphabet[2] + ' ' + _alphabet[3] + ' ' + _alphabet[4];
	board[2] = board[2] + _alphabet[5] + ' ' + _alphabet[6] + ' ' + _alphabet[7] + ' ' + _alphabet[8] + ' ' + _alphabet[9];
	board[3] = board[3] + _alphabet[10] + ' ' + _alphabet[11] + ' ' + _alphabet[12] + ' ' + _alphabet[13] + ' ' + _alphabet[14];
	board[4] = board[4] + _alphabet[15] + ' ' + _alphabet[16] + ' ' + _alphabet[17] + ' ' + _alphabet[18] + ' ' + _alphabet[19];
	board[5] = board[5] + _alphabet[20] + ' ' + _alphabet[21] + ' ' + _alphabet[22] + ' ' + _alphabet[23] + ' ' + _alphabet[24];
	board[6] = board[6] + _alphabet[25];

	std::cout << board[0] << std::endl;
	std::cout << board[1] << std::endl;
	std::cout << board[2] << std::endl;
	std::cout << board[3] << std::endl;
	std::cout << board[4] << std::endl;
	std::cout << board[5] << std::endl;
	std::cout << board[6] << std::endl;
	std::cout << board[7] << std::endl;
	std::cout << board[8] << std::endl << std::endl;;

	board[0] = "  ======= ";
	board[1] = "  |     |    ";
	board[2] = "  |     O    ";
	board[3] = "  |    /|\\   ";
	board[4] = "  |     |    ";
	board[5] = "  |    / \\   ";
	board[6] = "  |          ";
	board[7] = "=====     ";
	board[8] = "      ";
	fill_space = word;
	board[8] = board[8] + fill_space;
	for (size_t i = 0; i < 26; ++i) {
		_alphabet[i] = char(65 + i);
	}

	board[1] = board[1] + _alphabet[0] + ' ' + _alphabet[1] + ' ' + _alphabet[2] + ' ' + _alphabet[3] + ' ' + _alphabet[4];
	board[2] = board[2] + _alphabet[5] + ' ' + _alphabet[6] + ' ' + _alphabet[7] + ' ' + _alphabet[8] + ' ' + _alphabet[9];
	board[3] = board[3] + _alphabet[10] + ' ' + _alphabet[11] + ' ' + _alphabet[12] + ' ' + _alphabet[13] + ' ' + _alphabet[14];
	board[4] = board[4] + _alphabet[15] + ' ' + _alphabet[16] + ' ' + _alphabet[17] + ' ' + _alphabet[18] + ' ' + _alphabet[19];
	board[5] = board[5] + _alphabet[20] + ' ' + _alphabet[21] + ' ' + _alphabet[22] + ' ' + _alphabet[23] + ' ' + _alphabet[24];
	board[6] = board[6] + _alphabet[25];

	std::cout << board[0] << std::endl;
	std::cout << board[1] << std::endl;
	std::cout << board[2] << std::endl;
	std::cout << board[3] << std::endl;
	std::cout << board[4] << std::endl;
	std::cout << board[5] << std::endl;
	std::cout << board[6] << std::endl;
	std::cout << board[7] << std::endl;
	std::cout << board[8] << std::endl << std::endl;;
}

int main(void) {
	//GameCLI game;

	////show welcome message
	//std::cout << "== Welcome to Hangman! ==" << std::endl << std::endl;

	//do {
	//	//prompt for word or guesser's input
	//	game.prompt();

	//	//draw the board to the screen
	//	game.draw_board();
	//} while (game.is_running());

	draw();

	return 0;
}