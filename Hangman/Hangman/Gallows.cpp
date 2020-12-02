#include "Gallows.h"
Gallows::Gallows(void)
	:_body_complete(false),
	_word_complete(false)
{
	this->_gallows[0] = "  ======= ";
	this->_gallows[1] = "  |     | ";
	this->_gallows[2] = "  |       ";
	this->_gallows[3] = "  |       ";
	this->_gallows[4] = "  |       ";
	this->_gallows[5] = "  |       ";
	this->_gallows[6] = "  |       ";
	this->_gallows[7] = "=====     ";
}

Gallows::Gallows(std::string word)
	:_body_complete(false),
	_word_complete(false),
	_word(word)
{
	this->_gallows[0] = "  ======= ";
	this->_gallows[1] = "  |     | ";
	this->_gallows[2] = "  |       ";
	this->_gallows[3] = "  |       ";
	this->_gallows[4] = "  |       ";
	this->_gallows[5] = "  |       ";
	this->_gallows[6] = "  |       ";
	this->_gallows[7] = "=====     ";
}

Gallows::Gallows(const Gallows& gallows)
	:_body_complete(gallows._body_complete),
	_word_complete(gallows._word_complete),
	_word(gallows._word)
{
	for (int i = 0; i < 8; ++i) {
		this->_gallows[i] = gallows._gallows[i];
	}

	for (int i = 0; i < 26; ++i) {
		this->_alphabet[i] = gallows._alphabet[i];
	}
}

Gallows::~Gallows(void)
{  }

Gallows& Gallows::operator = (const Gallows& gallows) {
	this->_body_complete = gallows._body_complete;
	this->_word_complete = gallows._word_complete;
	this->_word = gallows._word;

	for (int i = 0; i < 8; ++i) {
		this->_gallows[i] = gallows._gallows[i];
	}

	for (int i = 0; i < 26; ++i) {
		this->_alphabet[i] = gallows._alphabet[i];
	}
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
