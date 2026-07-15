#ifndef ROOM_H
#define ROOM_H

#include"game_obj.h"
class room
{
	my_str name;
	dynamic_array<game_obj> objects;
public:
	room();
	room(my_str t_name,dynamic_array<game_obj> t_ob);
	room(const room& other);
	room& operator=(const room& other);
	bool operator==(const room& other);
	bool operator!=(const room& other);
	my_str get_name();
	dynamic_array<game_obj>& get_objs();
	friend ostream& operator<<(ostream& out, const room& obj);
	~room();
};

#endif