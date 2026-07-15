#include"detective.h"

detective::detective():person(),experience_level(0),specialty("N/A"){}
detective::detective(my_str t_name, int t_age, char t_gen, int day, int month, int year, int t_exp, my_str t_spec,my_str t_role):person(t_name,t_age,t_gen,date(year,month,day)),experience_level(t_exp),specialty(t_spec),role(t_role){}
detective::detective(const detective& other):person(other.get_name(),other.get_age(),other.get_gender(),other.get_dob()),experience_level(other.experience_level),specialty(other.specialty),role(other.role){}
detective::detective(person per, int t_exp, my_str t_spec, my_str t_role):person(per),experience_level(t_exp),specialty(t_spec),role(t_role){}
detective& detective::operator=(const detective& other)
{
	person::person(other.get_name(), other.get_age(), other.get_gender(), other.get_dob());
	experience_level = other.experience_level;
	specialty = other.specialty;
	role = other.role;
	return *this;
}

my_str detective::get_role()
{
	return role;
}

my_str detective::get_specialty()
{
	return specialty;
}
int detective::get_exp()
{
	return experience_level;
}

ostream& operator<<(ostream& out, const detective& obj)
{
	out << "Name: " << obj.get_name() << "\n";
	out << "Age: " << obj.get_age() << "\n";
	if (obj.get_gender() == 'M')
		out << "Gender: Male" << "\n";
	else if (obj.get_gender() == 'F')
		out << "Gender: Female" << "\n";
	
	out << "Date Of Birth: " << obj.get_dob() << "\n";
	out << "Role: " << obj.role << "\n";
	out << "Experience Level: " << obj.experience_level<<" points" << "\n";
	out << "Specialty: " << obj.specialty << "\n";

	return out;
}

detective::~detective()
{
}