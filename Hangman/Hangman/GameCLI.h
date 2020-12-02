#pragma once
#include "Gallows.h"

class GameCLI {
public:
	//constructors, destructor, and assignment op
	GameCLI(void);
	GameCLI(const GameCLI& cli);
	~GameCLI(void);
	GameCLI& operator = (const GameCLI& cli);

	void prompt(void);
	void draw_board(void);
	bool is_running(void);

private:
	Gallows _game_board;
};

