#pragma once
#ifndef GALLOWS_H
#include <string>

class Gallows {
public:

	//constructors, destructor, and assignment op
	Gallows(void);
	Gallows(std::string word);
	Gallows(const Gallows& gallows);
	~Gallows(void);
	Gallows& operator = (const Gallows& gallows);

	std::string* get_gallows(void);
	bool is_body_complete(void);
	bool is_word_complete(void);
	
	void create_head(void);
	void create_body(void);
	void create_left_arm(void);
	void create_right_arm(void);
	void create_left_leg(void);
	void create_right_leg(void);

private:
	bool _body_complete;
	bool _word_complete;
	std::string _gallows[8];
	char _alphabet[26];
	std::string _word;
};
#endif // !GALLOWS_H

