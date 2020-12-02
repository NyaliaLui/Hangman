#include "Gallows.h"
Gallows::Gallows(void)
	:_body_complete(false),
	_word_complete(false),
	_word(""),
	_fill_space("")
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
	this->_gallows[8] = "      ";
	this->_gallows[8] = this->_gallows[8] + this->_fill_space;

	//update gallows with the alphabet
	this->_gallows[1] = this->_gallows[1] + this->_alphabet[0] + ' ' + this->_alphabet[1] + ' ' + this->_alphabet[2] + ' ' + this->_alphabet[3] + ' ' + this->_alphabet[4];
	this->_gallows[2] = this->_gallows[2] + this->_alphabet[5] + ' ' + this->_alphabet[6] + ' ' + this->_alphabet[7] + ' ' + this->_alphabet[8] + ' ' + this->_alphabet[9];
	this->_gallows[3] = this->_gallows[3] + this->_alphabet[10] + ' ' + this->_alphabet[11] + ' ' + this->_alphabet[12] + ' ' + this->_alphabet[13] + ' ' + this->_alphabet[14];
	this->_gallows[4] = this->_gallows[4] + this->_alphabet[15] + ' ' + this->_alphabet[16] + ' ' + this->_alphabet[17] + ' ' + this->_alphabet[18] + ' ' + this->_alphabet[19];
	this->_gallows[5] = this->_gallows[5] + this->_alphabet[20] + ' ' + this->_alphabet[21] + ' ' + this->_alphabet[22] + ' ' + this->_alphabet[23] + ' ' + this->_alphabet[24];
	this->_gallows[6] = this->_gallows[6] + this->_alphabet[25];
}

Gallows::Gallows(std::string word)
	:_body_complete(false),
	_word_complete(false),
	_word(word),
	_fill_space(word)
{
	//create the fill space
	for (size_t i = 0; i < this->_word.length(); ++i) {
		if (this->_word[i] != ' ') {
			this->_fill_space[i] = '_';
		}
	}

	//create the alphabet
	for (size_t i = 0; i < 26; ++i) {
		this->_alphabet[i] = '-';
	}

	//create empty gallows
	this->_gallows[0] = "  ======= ";
	this->_gallows[1] = "  |     | ";
	this->_gallows[2] = "  |       ";
	this->_gallows[3] = "  |       ";
	this->_gallows[4] = "  |       ";
	this->_gallows[5] = "  |       ";
	this->_gallows[6] = "  |       ";
	this->_gallows[7] = "=====     ";
	this->_gallows[8] = "      ";
	this->_gallows[8] = this->_gallows[8] + this->_fill_space;

	//update gallows with the alphabet
	this->_gallows[1] = this->_gallows[1] + this->_alphabet[0] + ' ' + this->_alphabet[1] + ' ' + this->_alphabet[2] + ' ' + this->_alphabet[3] + ' ' + this->_alphabet[4];
	this->_gallows[2] = this->_gallows[2] + this->_alphabet[5] + ' ' + this->_alphabet[6] + ' ' + this->_alphabet[7] + ' ' + this->_alphabet[8] + ' ' + this->_alphabet[9];
	this->_gallows[3] = this->_gallows[3] + this->_alphabet[10] + ' ' + this->_alphabet[11] + ' ' + this->_alphabet[12] + ' ' + this->_alphabet[13] + ' ' + this->_alphabet[14];
	this->_gallows[4] = this->_gallows[4] + this->_alphabet[15] + ' ' + this->_alphabet[16] + ' ' + this->_alphabet[17] + ' ' + this->_alphabet[18] + ' ' + this->_alphabet[19];
	this->_gallows[5] = this->_gallows[5] + this->_alphabet[20] + ' ' + this->_alphabet[21] + ' ' + this->_alphabet[22] + ' ' + this->_alphabet[23] + ' ' + this->_alphabet[24];
	this->_gallows[6] = this->_gallows[6] + this->_alphabet[25];
}

Gallows::Gallows(const Gallows& gallows)
	:_body_complete(gallows._body_complete),
	_word_complete(gallows._word_complete),
	_word(gallows._word),
	_fill_space(gallows._fill_space)
{
	for (int i = 0; i < GALLOWS_SIZE; ++i) {
		this->_gallows[i] = gallows._gallows[i];
	}

	for (int i = 0; i < ALPHABT_SIZE; ++i) {
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

	for (int i = 0; i < GALLOWS_SIZE; ++i) {
		this->_gallows[i] = gallows._gallows[i];
	}

	for (int i = 0; i < ALPHABT_SIZE; ++i) {
		this->_alphabet[i] = gallows._alphabet[i];
	}
}

void Gallows::set_word(std::string word) {
	//word can only be set if it wasn't set previously
	//(i.e. set word when fill space is not set)
	this->_word = word;
	this->_fill_space = word;

	for (size_t i = 0; i < this->_word.length(); ++i) {
		if (this->_word[i] != ' ') {
			this->_fill_space[i] = '_';
		}
	}

	//make sure the fill space is seen on the board
	this->_gallows[8] = this->_gallows[8] + this->_fill_space;
}

std::string* Gallows::get_gallows(void) {
	return this->_gallows;
}

bool Gallows::is_body_complete(void) {
	return this->_body_complete;
}

bool Gallows::is_word_complete(void) {
	return this->_word_complete;
}

void Gallows::update_row1(void) {
	this->_gallows[1] = this->_gallows[1] + this->_alphabet[0] + ' ' + this->_alphabet[1] + ' ' + this->_alphabet[2] + ' ' + this->_alphabet[3] + ' ' + this->_alphabet[4];
}

void Gallows::create_head(void) {
	this->_gallows[2] = "  |     O ";
	this->_gallows[2] = this->_gallows[2] + this->_alphabet[5] + ' ' + this->_alphabet[6] + ' ' + this->_alphabet[7] + ' ' + this->_alphabet[8] + ' ' + this->_alphabet[9];
}

void Gallows::create_body(void) {
	this->_gallows[3] = "  |     | ";
	this->_gallows[4] = "  |     | ";

	this->_gallows[3] = this->_gallows[3] + this->_alphabet[10] + ' ' + this->_alphabet[11] + ' ' + this->_alphabet[12] + ' ' + this->_alphabet[13] + ' ' + this->_alphabet[14];
	this->_gallows[4] = this->_gallows[4] + this->_alphabet[15] + ' ' + this->_alphabet[16] + ' ' + this->_alphabet[17] + ' ' + this->_alphabet[18] + ' ' + this->_alphabet[19];
}

void Gallows::create_left_arm(void) {
	//the left arm can only be created when the body already exists
	this->_gallows[3] = "  |    /| ";
	this->_gallows[3] = this->_gallows[3] + this->_alphabet[10] + ' ' + this->_alphabet[11] + ' ' + this->_alphabet[12] + ' ' + this->_alphabet[13] + ' ' + this->_alphabet[14];
}

void Gallows::create_right_arm(void) {
	//the right can can only be created when the left arm exists
	this->_gallows[3] = "  |    /|\\";
	this->_gallows[3] = this->_gallows[3] + this->_alphabet[10] + ' ' + this->_alphabet[11] + ' ' + this->_alphabet[12] + ' ' + this->_alphabet[13] + ' ' + this->_alphabet[14];
}

void Gallows::create_left_leg(void) {
	this->_gallows[5] = "  |    /  ";
	this->_gallows[5] = this->_gallows[5] + this->_alphabet[20] + ' ' + this->_alphabet[21] + ' ' + this->_alphabet[22] + ' ' + this->_alphabet[23] + ' ' + this->_alphabet[24];
}

void Gallows::create_right_leg(void) {
	//the right leg can only be created when the left leg exists
	this->_gallows[5] = "  |    / \\";
	this->_gallows[5] = this->_gallows[5] + this->_alphabet[20] + ' ' + this->_alphabet[21] + ' ' + this->_alphabet[22] + ' ' + this->_alphabet[23] + ' ' + this->_alphabet[24];

	//the body is complete when the right leg is created
	this->_body_complete = true;
}

void Gallows::update_row6(void) {
	this->_gallows[6] = this->_gallows[6] + this->_alphabet[25];
}
