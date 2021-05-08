#pragma once
#include <string>
using namespace std;
class DateTime 
{
public:
	DateTime();
	static string* GetFields(string dateTime);
	string ToString();
	int Seconds;
	int Minutes;
	int Hours;

	int Days;
	int Months;
	int Years;
};