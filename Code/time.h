#include<iostream>
using namespace std;
#ifndef TIME_H
#define TIME_H

class times
{
	int hour, min, secs;
public:
	times();
	times(int t_hr, int t_m, int t_s);
	times(const times& other);
	times& operator=(const times& other);
	bool operator==(const times& other);
	int get_hr();
	int get_min();
	int get_secs();
	friend ostream& operator<<(ostream& out, const times& obj);
	~times();
};

#endif