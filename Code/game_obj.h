#ifndef GAME_OBJ_H
#define GAME_OBJ_H
#include"mystr.h"
#include"clue.h"
#include"dynamic.h"

class game_obj
{
	my_str name;
	bool contains_clue;
	bool found;
	dynamic_array<clue> clues;
public:
	game_obj();
	game_obj(my_str t_name, bool cl, bool t_f, dynamic_array<clue> t_clues);
	game_obj(const game_obj& other);
	game_obj& operator=(const game_obj& other);
	bool operator==(const game_obj& other);
	bool operator!=(const game_obj& other);
	dynamic_array<clue>& get_clue();
	bool get_contains_cl();
	bool get_found();
	my_str get_name();
	friend ostream& operator<<(ostream& out, const game_obj& obj);
	~game_obj();
};

#endif 