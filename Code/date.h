#include<iostream>
using namespace std;
#ifndef DATE_H
#define DATE_H
class date
{
	int year, month, day;
	bool is_valid();

public:
	date();
	date(int temp_yr, int temp_mon, int temp_day);
	friend ostream& operator<<(ostream& out, const date& obj);
	date& operator=(const date& other);
	bool operator==(const date& other);
	int get_yr();
	int get_mon();
	int get_day();
	~date();
};

#endif