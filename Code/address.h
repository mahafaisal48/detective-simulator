#ifndef ADDRESS_H
#define ADDRESS_H
#include"mystr.h"

class address
{
	int house_number;
	my_str city, society, country;

public:
	address();
	address(int t_hrsno, my_str temp_city, my_str temp_soc, my_str temp_country);
	friend ostream& operator<<(ostream& out, const address& obj);
};

#endif