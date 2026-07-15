#ifndef DETECTIVE_H
#define DETECTIVE_H
#include"person.h"

class detective :public person
{
	my_str role;
	my_str specialty;
	int experience_level;
public:
	detective();
	detective(my_str t_name, int t_age, char t_gen, int day, int month, int year, int t_exp, my_str t_spec,my_str t_role);
	detective(person per, int t_exp, my_str t_spec, my_str t_role);
	detective(const detective& other);
	my_str get_role();
	my_str get_specialty();
	int get_exp();
	detective& operator=(const detective& other);
	friend ostream& operator<<(ostream& out, const detective& obj);
	~detective() override;
};

#endif