#include"room.h"

room::room():name("N/A"),objects(){}
room::room(my_str t_name, dynamic_array<game_obj> t_ob):name(t_name),objects(t_ob){}
room::room(const room& other):name(other.name),objects(other.objects){}
room& room::operator=(const room& other)
{
	name = other.name;
	objects = other.objects;
	return *this;
}

bool room::operator==(const room& other)
{
	if (!(name == other.name))
		return false;

	if (objects != other.objects)
		return false;

	return true;
}

bool room::operator!=(const room& other)
{
	if (!(*this == other))
		return true;

	return false;
}

my_str room::get_name()
{
	return name;
}

dynamic_array<game_obj>& room::get_objs()
{
	return objects;
}

ostream& operator<<(ostream& out, const room& obj)
{
	out << obj.name << "\n";
	obj.objects.print();
	return out;
}

room::~room(){}