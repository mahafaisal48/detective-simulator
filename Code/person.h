#ifndef PERSON_H
#define PERSON_H
#include"mystr.h"
#include"date.h"

class person
{
	my_str name;
	int age;
	char gender;
	date dob;

public:
	person();
	person(my_str t_name, int t_age, char t_gender, int day,int month,int yr);
	person(my_str t_name, int t_age, char t_gender, date t_dob);
	person(const person& other);
	person& operator=(const person& other);
	my_str get_name() const;
	int get_age()const;
	char get_gender()const;
	date get_dob()const;
	bool operator==(const person& other);
	bool operator!=(const person& other);
	friend ostream& operator<<(ostream& out, const person& obj);
	virtual ~person();
};

#endif