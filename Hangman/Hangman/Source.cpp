#include "GameCLI.h"
#include <iostream>

int main(void) {
	GameCLI game;

	//show welcome message
	std::cout << "== Welcome to Hangman! ==" << std::endl << std::endl;

	do {
		//prompt for word or guesser's input
		game.prompt();

		//draw the board to the screen
		game.draw_board();
	} while (game.is_running());


	return 0;
}