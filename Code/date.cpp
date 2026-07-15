#include"date.h"

date::date() :year(0), month(0), day(0)
{
}

date::date(int temp_yr, int temp_mon, int temp_day) :year(temp_yr), month(temp_mon), day(temp_day)
{
	bool validity = this->is_valid();
	if (!validity)
	{
		day = 0;
		month = 0;
		year = 0;
	}
}

bool date::is_valid()
{
	if (year < 1950 || year > 2025)
	{
		return false;
	}

	if (month < 1 || month>12)
	{
		return false;
	}

	if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12)
	{
		if (day < 1 || day>31)
		{
			return false;
		}
	}

	if (month == 4 || month == 6 || month == 9 || month == 11)
	{
		if (day < 1 || day>30)
		{
			return false;
		}
	}

	if (month == 2)
	{
		bool leap_yr = false;
		if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))
		{
			leap_yr = true;
		}

		if (leap_yr)
		{
			if (day < 1 || day > 29)
			{
				return false;
			}
		}

		else
		{
			if (day < 1 || day > 28)
			{
				return false;
			}
		}
	}
	return true;
}

bool date::operator==(const date& other)
{
	if (year != other.year)
		return false;
	if (month != other.month)
		return false;
	if (day != other.day)
		return false;

	return true;
}

date& date::operator=(const date& other)
{
	year = other.year;
	month = other.month;
	day = other.day;
	return *this;
}

int date::get_yr()
{
	return year;
}

int date::get_mon()
{
	return month;
}

int date::get_day()
{
	return day;
}

ostream& operator<<(ostream& out, const date& obj)
{
	out << obj.year << "/" << obj.month << "/" << obj.day<<"\n";
	return out;
}

date::~date(){}