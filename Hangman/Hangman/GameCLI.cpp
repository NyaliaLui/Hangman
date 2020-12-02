#include "GameCLI.h"
#include <iostream>

GameCLI::GameCLI(void)
{  }

GameCLI::GameCLI(const GameCLI& cli)
	:_game_board(cli._game_board)
{  }

GameCLI::~GameCLI(void)
{  }

GameCLI& GameCLI::operator = (const GameCLI& cli) {
	this->_game_board = cli._game_board;
}

void GameCLI::prompt(void) {
	std::string input;

	std::cout << "What is the guessing word/phrase? --> ";
	std::getline(std::cin, input);

	this->_game_board.set_word(input);
}

void GameCLI::draw_board(void) {
	std::string* gallows = this->_game_board.get_gallows();

	for (size_t i = 0; i < GALLOWS_SIZE; ++i) {
		std::cout << gallows[i] << std::endl;
	}
	std::cout << std::endl;
}

bool GameCLI::is_running(void) {
	bool is_finished = false;
	is_finished = this->_game_board.is_body_complete() || this->_game_board.is_word_complete();
	return (!is_finished);
}