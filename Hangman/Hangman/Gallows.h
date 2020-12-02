#pragma once
#ifndef GALLOWS_H
#include <string>
#include <array>
#define BOARD_SIZE 10
#define GALLOWS_SIZE 8
#define ALPHABT_SIZE 26

class Gallows {
public:

	//constructors, destructor, and assignment op
	Gallows(void);
	Gallows(const Gallows& gallows);
	~Gallows(void);
	Gallows& operator = (const Gallows& gallows);

	void user_guess(char c);
	void user_guess(std::string str);
	void set_word(std::string word);
	std::array<std::string, BOARD_SIZE>& get_board(void);
	bool is_body_complete(void);
	bool is_word_complete(void);
	
	void update_board(void);
	void update_fill_space(void);
	void create_head(void);
	void create_body(void);
	void create_left_arm(void);
	void create_right_arm(void);
	void create_left_leg(void);
	void create_right_leg(void);

private:
	bool _body_complete;
	bool _word_complete;
	std::array<std::string, BOARD_SIZE> _board;
	std::array<std::string, GALLOWS_SIZE> _gallows;
	std::array<char, ALPHABT_SIZE> _alphabet;
	std::string _word;
	std::string _fill_space;
	size_t _attempt;
};
#endif // !GALLOWS_H

