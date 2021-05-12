#pragma once
#include <string>
#include <vector>
using namespace std;
class DateTime 
{
public:
	DateTime();
	static vector<string> GetFields(string dateTime);
	string ToString();
	int Seconds;
	int Minutes;
	int Hours;

	int Days;
	int Months;
	int Years;
};