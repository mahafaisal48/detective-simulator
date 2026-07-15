#include"person.h"

person::person() :name("N/A"), age(-1), gender('N'), dob(0, 0, 0) {}
person::person(my_str t_name, int t_age, char t_gender, int day, int month, int yr):name(t_name),age(t_age),gender(t_gender),dob(yr,month,day){}
person::person(my_str t_name, int t_age, char t_gender, date t_dob):name(t_name),age(t_age),gender(t_gender),dob(t_dob){}
person::person(const person& other):name(other.name),age(other.age),gender(other.gender),dob(other.dob){}
person& person::operator=(const person& other)
{
	name = other.name;
	age = other.age;
	gender = other.gender;
	dob = other.dob;
	return *this;
}

my_str person::get_name() const
{
	return name;
}

int person::get_age()const
{
	return age;
}

char person::get_gender()const
{
	return gender;
}

date person::get_dob()const
{
	return dob;
}

bool person::operator==(const person& other)
{
	if (!(name == other.name))
		return false;
	if (age != other.age)
		return false;
	if (gender != other.gender)
		return false;
	if (!(dob == other.dob))
		return false;

	return true;
}

bool person::operator!=(const person& other)
{
	if (!(*this == other))
		return true;
	return false;
}

ostream& operator<<(ostream& out, const person& obj)
{
	out << "Name: " << obj.name << "\n" << "Age: " << obj.age<<"\n";
	if (obj.gender == 'M')
		out << "Gender: Male" << "\n";
	else if (obj.gender == 'F')
		out << "Gender: Female" << "\n";

	out << "Date Of Birth: " << obj.dob << "\n";
	return out;
}

person::~person()
{
}