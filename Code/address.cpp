#include"address.h"

address::address()
{
}

address::address(int t_hrsno, my_str temp_city, my_str temp_soc, my_str temp_country) :house_number(t_hrsno), city(temp_city), society(temp_soc), country(temp_country)
{
}

ostream& operator<<(ostream& out, const address& obj)
{
	out<< obj.house_number<<" "<< obj.society<<", " << obj.city<<", " << obj.country;
	return out;
}