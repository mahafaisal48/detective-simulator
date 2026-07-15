#ifndef SUSPECT_H
#define SUSPECT_H 
#include"person.h"
#include"mystr.h"
#include"alibi.h"

class suspect:public person
{
	my_str occupation;
	my_str relation_with_deceased;
	alibi alibi_detail;
	bool is_killer;
public:
	suspect();
	suspect(my_str t_name, int t_age, char t_gen, int day, int month, int year,my_str t_occ,my_str t_rel, alibi t_alibi,bool t_kill);
	suspect(const suspect& other);
	suspect& operator=(const suspect& other);
	bool operator==(const suspect& other);
	bool operator!=(const suspect& other);
	my_str get_occupation();
	my_str get_relation();
	alibi get_alibi();
	bool get_is_killer();
	friend ostream& operator<<(ostream& out, const suspect& obj);
	~suspect() override;
};

#endif