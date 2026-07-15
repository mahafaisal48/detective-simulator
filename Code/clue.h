#ifndef CLUE_H
#define CLUE_H
#include"mystr.h"

class clue
{
	my_str description;
	bool misleading;

public:
	clue();
	clue(my_str t_d, bool t_mis);
	clue(const clue& other);
	clue& operator=(const clue& other);
	bool operator==(const clue& other);
	bool operator!=(const clue& other);
	my_str get_descr() const;
	friend ostream& operator<<(ostream& out, const clue& obj);
	~clue();
};

#endif