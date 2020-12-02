#include "GameCLI.h"
#include <iostream>
#include <iostream>
#include <cctype>

GameCLI::GameCLI(void)
	:_word_is_set(false)
{  }

GameCLI::GameCLI(const GameCLI& cli)
	:_game_board(cli._game_board),
	_word_is_set(false)
{  }

GameCLI::~GameCLI(void)
{  }

GameCLI& GameCLI::operator = (const GameCLI& cli) {
	this->_game_board = cli._game_board;
	this->_word_is_set = cli._word_is_set;

	return (*this);
}

void GameCLI::prompt(void) {
	std::string input;

	if (this->_word_is_set) {
		std::cout << "What letter do you guess?" << std::endl;
		std::cout << "Alternatively, you can try to guess the whole word/phrase." << std::endl;
		std::cout << "-- > ";
		std::getline(std::cin, input);

		if (input[1] && input[1] != ' ') {
			for (size_t i = 0; i < input.length(); ++i) {
				if (input[i] != ' ') {
					input[i] = char(std::toupper(input[i]));
				}
			}

			this->_game_board.user_guess(input);
		}
		else {
			char c = std::toupper(input[0]);
			this->_game_board.user_guess(c);
		}
	}
	else {
		std::string input;
		std::cout << "What is the guessing word/phrase? --> ";
		std::getline(std::cin, input);
		this->_game_board.set_word(input);
		this->_word_is_set = true;
	}
}

void GameCLI::draw_board(void) {
	std::array<std::string, BOARD_SIZE>& board = this->_game_board.get_board();

	for (std::string &str : board) {
		std::cout << str << std::endl;
	}
	std::cout << std::endl;
}

bool GameCLI::is_running(void) {
	bool is_finished = false;
	is_finished = this->_game_board.is_body_complete() || this->_game_board.is_word_complete();
	return (!is_finished);
}