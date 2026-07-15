#include"suspect.h"

suspect::suspect() :person(), occupation("N/A"), relation_with_deceased("N/A"), alibi_detail(),is_killer(false){}
suspect::suspect(my_str t_name, int t_age, char t_gen, int day, int month, int year, my_str t_occ, my_str t_rel, alibi t_alibi,bool t_kill)
	:person(t_name,t_age,t_gen,day,month,year),occupation(t_occ),relation_with_deceased(t_rel),alibi_detail(t_alibi),is_killer(t_kill){}
suspect::suspect(const suspect& other)
	:person(other.get_name(),other.get_age(),other.get_gender(),other.get_dob()),occupation(other.occupation),relation_with_deceased(other.relation_with_deceased),alibi_detail(other.alibi_detail),is_killer(other.is_killer){}
suspect& suspect::operator=(const suspect& other)
{
	person::operator=(other);
	occupation = other.occupation;
	relation_with_deceased = other.relation_with_deceased;
	alibi_detail = other.alibi_detail;
	is_killer = other.is_killer;
	return *this;
}

bool suspect::operator==(const suspect& other)
{
	if (person::operator!=(other))
		return false;
	if (!(occupation == other.occupation))
		return false;
	if (!(relation_with_deceased == other.relation_with_deceased))
		return false;
	if (!(alibi_detail == other.alibi_detail))
		return false;
	if (is_killer != other.is_killer)
		return false;

	return true;
}

bool suspect::operator!=(const suspect& other)
{
	if (!(*this == other))
		return true;

	return false;
}

my_str suspect::get_occupation()
{
	return occupation;
}

my_str suspect::get_relation()
{
	return relation_with_deceased;
}

alibi suspect::get_alibi()
{
	return alibi_detail;
}

bool suspect::get_is_killer()
{
	return is_killer;
}

ostream& operator<<(ostream& out, const suspect& obj)
{
	out << "Name: " << obj.get_name() << "\n";
	out << "Age: " << obj.get_age() << "\n";
	if (obj.get_gender() == 'M')
		out << "Gender: Male" << "\n";
	else if (obj.get_gender() == 'F')
		out << "Gender: Female" << "\n";

	out << "Date Of Birth: " << obj.get_dob() << "\n";
	out << "Occupation: " << obj.occupation << "\n";
	out << "Relation with Deceased: " << obj.relation_with_deceased << "\n";
	return out;
}

suspect::~suspect(){}