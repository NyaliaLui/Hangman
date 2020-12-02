#pragma once
#ifndef GALLOWS_H
#include <string>
#define GALLOWS_SIZE 9
#define ALPHABT_SIZE 26

class Gallows {
public:

	//constructors, destructor, and assignment op
	Gallows(void);
	Gallows(std::string word);
	Gallows(const Gallows& gallows);
	~Gallows(void);
	Gallows& operator = (const Gallows& gallows);

	void set_word(std::string word);
	std::string* get_gallows(void);
	bool is_body_complete(void);
	bool is_word_complete(void);
	
	void update_row1(void);
	void create_head(void);
	void create_body(void);
	void create_left_arm(void);
	void create_right_arm(void);
	void create_left_leg(void);
	void create_right_leg(void);
	void update_row6(void);

private:
	bool _body_complete;
	bool _word_complete;
	std::string _gallows[GALLOWS_SIZE];
	char _alphabet[ALPHABT_SIZE];
	std::string _word;
	std::string _fill_space;
};
#endif // !GALLOWS_H

