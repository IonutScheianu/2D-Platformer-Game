#include "Date.h"
#include<iostream>
#include<ctime>

Date::Date()
{
	m_day = NULL;
	m_month = NULL;
	m_year = NULL;
}

Date::Date(unsigned int day, unsigned int month, unsigned int year)
{
	m_day = day;
	m_month = month;
	m_year = year;
}


Date::~Date()
{
}

std::ostream &operator<<(std::ostream &output, const Date &date)
{
	//output << "Date: ";
	output << date.m_day << "/" << date.m_month << "/" << date.m_year;
	return output;
}

std::istream &operator>>(std::istream &input, Date &date)
{
	Date currentDate;
	currentDate.getCurrentDate();
	std::cout << "Insert a date(dd/mm/yyyy): ";
	input >> date.m_day >> date.m_month >> date.m_year;
	if (date<currentDate)
	{
		throw "Invalide date";
	}
	return input;
}

Date Date::operator=(const Date &date2)
{
	m_year = date2.m_year;
	m_month = date2.m_month;
	m_day = date2.m_day;
	return *this;
}


bool Date::operator<(const Date &date2)const
{
	if (m_year == date2.m_year)
	{
		if (m_month == date2.m_month)
		{
			if (m_day == date2.m_day)
			{
				return false;
			}
			else
			{
				if (m_day < date2.m_day)
				{
					return true;
				}
				else
				{
					return false;
				}
			}
		}
		else
		{
			if (m_month < date2.m_month)
			{
				return true;
			}
			else
			{
				return false;
			}
		}
	}
	else
	{
		if (m_year < date2.m_year)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
}


bool Date::operator>(const Date &date2)const
{
	if (m_year == date2.m_year)
	{
		if (m_month == date2.m_month)
		{
			if (m_day == date2.m_day)
			{
				return false;
			}
			else
			{
				if (m_day > date2.m_day)
				{
					return true;
				}
				else
				{
					return false;
				}
			}
		}
		else
		{
			if (m_month > date2.m_month)
			{
				return true;
			}
			else
			{
				return false;
			}
		}
	}
	else
	{
		if (m_year > date2.m_year)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
}

bool Date::operator==(const Date &date2)
{
	if (m_year == date2.m_year && m_month == date2.m_month && m_day == date2.m_day)
	{
		return true;
	}
	else
	{
		return false;
	}
}

unsigned int Date::getDay()
{
	return m_day;
}

unsigned int Date::getMonth()
{
	return m_month;
}

unsigned int Date::getYear()
{
	return m_year;
}

void Date::setDay(unsigned int day)
{
	m_day = day;
}

void Date::setMonth(unsigned int month)
{
	m_month = month;
}

void Date::setYear(unsigned int year)
{
	m_year = year;
}

void Date::updateAll(unsigned int day, unsigned int month, unsigned int year)
{
	m_day = day;
	m_month = month;
	m_year = year;
}

Date Date::getCurrentDate()
{
	time_t rawTime;
	struct tm timeInfo;
	time(&rawTime);
	localtime_s(&timeInfo, &rawTime);
	m_day = timeInfo.tm_mday;
	m_month = timeInfo.tm_mon;
	m_year = timeInfo.tm_year+1900;

	return *this;
}

