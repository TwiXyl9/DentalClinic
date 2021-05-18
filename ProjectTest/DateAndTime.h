#pragma once
#include <string>
#include <vector>
using namespace std;
class DateAndTime 
{
public:
	DateAndTime();
	static vector<string> GetDateFields(string dateTime);
	static vector<string> GetDateAndTimeFields(string dateTime);
	static DateAndTime ToDateAndTime(System::DateTime dateTime);
	string TimeToString();
	string DateAndTimeToString();
	string ToString();
	int Seconds;
	int Minutes;
	int Hours;

	
	int Days;
	int Months;
	int Years;
};