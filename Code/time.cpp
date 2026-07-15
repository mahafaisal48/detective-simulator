#include"time.h"

times::times():hour(00),min(00),secs(00){}
times::times(int t_hr, int t_m, int t_s):hour(t_hr),min(t_m),secs(t_s){}
times::times(const times& other) :hour(other.hour), min(other.min), secs(other.secs){}
times& times::operator=(const times& other)
{
	if (this != &other)
	{
		hour = other.hour;
		min = other.min;
		secs = other.secs;
	}
	return *this;
}

bool times::operator==(const times& other)
{
	if (hour != other.hour)
		return false;

	if (min != other.min)
		return false;

	if (secs != other.secs)
		return false;

	return true;
}

int times::get_hr()
{
	return hour;
}

int times::get_min()
{
	return min;
}
int times::get_secs()
{
	return secs;
}

ostream& operator<<(ostream& out, const times& obj)
{
	out << obj.hour << ":" << obj.min << ":" << obj.secs;
	return out;
}

times::~times()
{
}