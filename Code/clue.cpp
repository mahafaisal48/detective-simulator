#include<iostream>
using namespace std;
#include"clue.h"

clue::clue():description("N/A"),misleading(false){}
clue::clue(my_str t_d, bool t_mis):description(t_d),misleading(t_mis){}
clue::clue(const clue& other): description(other.description), misleading(other.misleading) {}
clue& clue::operator=(const clue& other)
{
	if (this != &other)
	{
		description = other.description;
		misleading = other.misleading;
	}
	return *this;
}

bool clue::operator==(const clue& other)
{
	if (description == other.description && misleading == other.misleading)
		return true;
	else
		return false;
}

bool clue::operator!=(const clue& other)
{
	if (!(*this == other))
		return true;
	else
		return false;
}

my_str clue::get_descr() const
{
	return description;
}

ostream& operator<<(ostream& out, const clue& obj)
{
	out << obj.get_descr() << "\n";
	return out;
}

clue::~clue()
{
	//description.clear();
}