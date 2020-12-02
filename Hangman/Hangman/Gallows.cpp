#include "Gallows.h"
#include <algorithm>
#include <cctype>
#include <iostream>
#define MAX_ATTEMPTS 6

Gallows::Gallows(void)
	:_body_complete(false),
	_word_complete(false),
	_word(""),
	_fill_space(""),
	_attempt(0)
{
	//set the alphabet
	for (size_t i = 0; i < 26; ++i) {
		this->_alphabet[i] = '-';
	}

	//create empty gallows
	this->_gallows[0] = "  ======= ";
	this->_gallows[1] = "  |     |    ";
	this->_gallows[2] = "  |          ";
	this->_gallows[3] = "  |          ";
	this->_gallows[4] = "  |          ";
	this->_gallows[5] = "  |          ";
	this->_gallows[6] = "  |          ";
	this->_gallows[7] = "=====     ";

	//update the whole board with the gallows and the alphabet
	this->update_board();
	this->update_fill_space();
	this->_board[9] = " ";
}

Gallows::Gallows(const Gallows& gallows)
	:_body_complete(gallows._body_complete),
	_word_complete(gallows._word_complete),
	_word(gallows._word),
	_fill_space(gallows._fill_space),
	_attempt(gallows._attempt)
{
	for (size_t i = 0; i < BOARD_SIZE; ++i) {
		this->_board[i] = gallows._board[i];
	}

	for (size_t i = 0; i < GALLOWS_SIZE; ++i) {
		this->_board[i] = gallows._board[i];
		this->_gallows[i] = gallows._gallows[i];
	}

	for (size_t i = 0; i < ALPHABT_SIZE; ++i) {
		this->_alphabet[i] = gallows._alphabet[i];
	}
}

Gallows::~Gallows(void)
{  }

Gallows& Gallows::operator = (const Gallows& gallows) {
	this->_body_complete = gallows._body_complete;
	this->_word_complete = gallows._word_complete;
	this->_word = gallows._word;
	this->_fill_space = gallows._fill_space;
	this->_attempt = gallows._attempt;

	for (size_t i = 0; i < BOARD_SIZE; ++i) {
		this->_board[i] = gallows._board[i];
	}

	for (size_t i = 0; i < GALLOWS_SIZE; ++i) {
		this->_gallows[i] = gallows._gallows[i];
	}

	for (size_t i = 0; i < ALPHABT_SIZE; ++i) {
		this->_alphabet[i] = gallows._alphabet[i];
	}

	return (*this);
}

void Gallows::user_guess(char c) {
	size_t index = 0, last_pos = 0;
	bool found_letter = false;

	//if the letter is found, replace every occurance
	//of the letter in fill space
	do {
		index = this->_word.find(c, last_pos);

		if (index != std::string::npos) {
			std::cout << "??? " << last_pos << std::endl;
			this->_board[9] = "Letter found! :)";
			this->_fill_space[index] = c;
			last_pos = index + 1;
			found_letter = true;
		}
		else if (!found_letter) {
			this->_board[9] = "Letter not found :(";
			++this->_attempt;
		}
	} while (index != std::string::npos);

	//mark the letter in the alphabet list
	this->_alphabet[int(c) - 65] = c;

	//mark the proper body part if the letter was not found
	//(i.e. found_letter is true)
	if (!found_letter) {
		switch (this->_attempt) {
		case 1:
			this->create_head();
			break;

		case 2:
			this->create_body();
			break;

		case 3:
			this->create_left_arm();
			break;

		case 4:
			this->create_right_arm();
			break;

		case 5:
			this->create_left_leg();
			break;

		case 6:
			this->create_right_leg();
			break;

		default:
			break;
		}
	}

	//check if the word was completed
	this->_word_complete = (this->_fill_space.find('_') == std::string::npos);

	//update the whole board
	this->update_board();

	//update the fill_space
	this->update_fill_space();
}

void Gallows::set_word(std::string word) {
	//word can only be set if it wasn't set previously
	//(i.e. set word when fill space is not set)
	this->_word = word;
	this->_fill_space = word;

	for (size_t i = 0; i < this->_word.length(); ++i) {
		if (this->_word[i] != ' ') {
			this->_fill_space[i] = '_';
			char c = std::toupper(this->_word[i]);
			this->_word[i] = c;
		}
	}

	std::cout << this->_word << std::endl;
	std::cout << this->_fill_space << std::endl;

	//make sure the fill space is seen on the board
	this->update_fill_space();
}

std::array<std::string, BOARD_SIZE>& Gallows::get_board(void) {
	return this->_board;
}

bool Gallows::is_body_complete(void) {
	return this->_body_complete;
}

bool Gallows::is_word_complete(void) {
	return this->_word_complete;
}

void Gallows::update_board(void) {
	this->_board[0] = this->_gallows[0];
	this->_board[1] = this->_gallows[1] + this->_alphabet[0] + ' ' + this->_alphabet[1] + ' ' + this->_alphabet[2] + ' ' + this->_alphabet[3] + ' ' + this->_alphabet[4];
	this->_board[2] = this->_gallows[2] + this->_alphabet[5] + ' ' + this->_alphabet[6] + ' ' + this->_alphabet[7] + ' ' + this->_alphabet[8] + ' ' + this->_alphabet[9];
	this->_board[3] = this->_gallows[3] + this->_alphabet[10] + ' ' + this->_alphabet[11] + ' ' + this->_alphabet[12] + ' ' + this->_alphabet[13] + ' ' + this->_alphabet[14];
	this->_board[4] = this->_gallows[4] + this->_alphabet[15] + ' ' + this->_alphabet[16] + ' ' + this->_alphabet[17] + ' ' + this->_alphabet[18] + ' ' + this->_alphabet[19];
	this->_board[5] = this->_gallows[5] + this->_alphabet[20] + ' ' + this->_alphabet[21] + ' ' + this->_alphabet[22] + ' ' + this->_alphabet[23] + ' ' + this->_alphabet[24];
	this->_board[6] = this->_gallows[6] + this->_alphabet[25];
	this->_board[7] = this->_gallows[7];
}

void Gallows::update_fill_space(void) {
	this->_board[8] = "      ";
	this->_board[8] = this->_board[8] + this->_fill_space;
}

void Gallows::create_head(void) {
	this->_gallows[2] = "  |     O ";
}

void Gallows::create_body(void) {
	this->_gallows[3] = "  |     | ";
	this->_gallows[4] = "  |     | ";
}

void Gallows::create_left_arm(void) {
	//the left arm can only be created when the body already exists
	this->_gallows[3] = "  |    /| ";
}

void Gallows::create_right_arm(void) {
	//the right can can only be created when the left arm exists
	this->_gallows[3] = "  |    /|\\";
}

void Gallows::create_left_leg(void) {
	this->_gallows[5] = "  |    /  ";
}

void Gallows::create_right_leg(void) {
	//the right leg can only be created when the left leg exists
	this->_gallows[5] = "  |    / \\";

	//the body is complete when the right leg is created
	this->_body_complete = true;
}
