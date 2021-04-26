#pragma once
class Date
{
public:
	Date();
	Date(int day, int month, int year);
	void setDay(int day);
	int getDay();
	void setMonth(int month);
	int getMonth();
	void setYear(int year);
	int getYear();
private:
	int month;
	int year;
	int day;
};

