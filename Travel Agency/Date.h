#include<iostream>
#include <ostream>
#include<istream>
#pragma once
class Date
{
private:
	unsigned int m_day;
	unsigned int m_month;
	unsigned int m_year;
public:
	Date();
	Date(unsigned int day, unsigned int month, unsigned int year);
	friend std::ostream& operator<<(std::ostream& output, const Date &date);
	friend std::istream& operator>>(std::istream& input, Date &date);
	Date operator=(const Date &date2);
	bool operator<(const Date &date2)const;
	bool operator>(const Date &date2)const;
	bool operator==(const Date &date2);
	unsigned int getDay();
	unsigned int getMonth();
	unsigned int getYear();
	void setDay(unsigned int day);
	void setMonth(unsigned int month);
	void setYear(unsigned int year);
	void updateAll(unsigned int day, unsigned int month, unsigned int year);
	Date getCurrentDate();
	~Date();
};

