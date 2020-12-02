#include "GameCLI.h"

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

}

void GameCLI::draw_board(void) {

}

bool GameCLI::is_running(void) {
	bool is_finished = false;
	is_finished = this->_game_board.is_body_complete() || this->_game_board.is_word_complete();
	return (!is_finished);
}