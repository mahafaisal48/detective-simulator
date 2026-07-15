#include"investigation_case.h"
investigation::investigation():case_title(),case_description(),house_address(),suspects(),rooms(){}
investigation::investigation(my_str title, my_str descr, address t_addr, dynamic_array<suspect> t_suspects,dynamic_array<room> t_rooms)
	:case_title(title),case_description(descr),house_address(t_addr),suspects(t_suspects),rooms(t_rooms){}
investigation::investigation(const investigation& other)
	:case_title(other.case_title),case_description(other.case_description),house_address(other.house_address),suspects(other.suspects),rooms(other.rooms){}
investigation& investigation::operator=(const investigation& other)
{
	case_title = other.case_title;
	case_description = other.case_description;
	house_address = other.house_address;
	suspects = other.suspects;
	rooms = other.rooms;
	return *this;
}

address investigation::get_address()
{
	return house_address;
}

dynamic_array<suspect>& investigation::get_suspects()
{
	return suspects;
}

dynamic_array<room>& investigation::get_rooms()
{
	return rooms;
}

ostream& operator<<(ostream& out, const investigation& obj)
{
	out << obj.case_title << "\n";
	out << obj.case_description << "\n";
	return out;
}

investigation::~investigation()
{
}