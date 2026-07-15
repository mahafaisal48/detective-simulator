#include"alibi.h"

alibi::alibi() :statement("N/A"), location("N/A"), timing(), witness("N/A"), verified(true){}
alibi::alibi(my_str t_s, my_str t_loc, int hour, int min, int secs, my_str t_w, bool t_ver):statement(t_s),location(t_loc),timing(hour,min,secs),witness(t_w),verified(t_ver){}
alibi::alibi(const alibi& other):statement(other.statement),location(other.location),timing(other.timing),witness(other.witness),verified(other.verified){}
alibi& alibi::operator=(const alibi& other)
{
	statement = other.statement;
	location = other.location;
	timing = other.timing;
	witness = other.witness;
	verified = other.verified;
	return *this;
}

bool alibi::operator==(const alibi& other)
{
	if (!(statement == other.statement))
		return false;

	if (!(location == other.location))
		return false;

	if (!(timing == other.timing))
		return false;

	if (verified != other.verified)
		return false;

	return true;
}

void alibi::statement_print()
{
	statement.print();
}

void alibi::location_print()
{
	cout << "I was in the ";
	location.print();
}

void alibi::time_print()
{
	cout << timing << "\n";
}

void alibi::witness_print()
{
	cout << "My witness is ";
	witness.print();
}

my_str alibi::get_statement()
{
	return statement;
}

my_str alibi::get_location()
{
	return location;
}

times alibi::get_timing()
{
	return timing;
}

my_str alibi::get_witness()
{
	return witness;
}

bool alibi::get_ver()
{
	return verified;
}

alibi::~alibi()
{
}