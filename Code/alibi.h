#ifndef ALIBI_H
#define ALIBI_H
#include"mystr.h"
#include"time.h"

class alibi
{
	my_str statement;
	my_str location;
	times timing; //time that they will tell regarding activity that they were doing this at this time
	my_str witness;
	bool verified; //alibis can be false keep this fr hard medium level etc
public:
	alibi();
	alibi(my_str t_s, my_str t_loc, int hour,int min, int secs, my_str t_w, bool t_ver);
	alibi(const alibi& other);
	alibi& operator=(const alibi& other);
	bool operator==(const alibi& other);
	void statement_print();
	void location_print();
	void time_print();
	void witness_print();
	my_str get_statement();
	my_str get_location();
	times get_timing();
	my_str get_witness();
	bool get_ver();
	~alibi();
};

#endif