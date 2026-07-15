#ifndef INVESTIGATION_H
#define INVESTIGATION_H
#include"mystr.h"
#include"address.h"
#include"dynamic.h"
#include"suspect.h"
#include"game_obj.h"
#include"room.h"

class investigation
{
	my_str case_title;
	my_str case_description;
	address house_address;
	dynamic_array<suspect> suspects;
	dynamic_array<room> rooms;

public:
	investigation();
	investigation(my_str title, my_str descr, address t_addr, dynamic_array<suspect> t_suspects, dynamic_array<room> t_rooms);
	investigation(const investigation& other);
	investigation& operator=(const investigation& other);
	dynamic_array<suspect>& get_suspects();
	dynamic_array<room>& get_rooms();
	address get_address();
	friend ostream& operator<<(ostream& out, const investigation& obj);
	~investigation();
};

#endif