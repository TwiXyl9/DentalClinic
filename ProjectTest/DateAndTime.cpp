#include "DateAndTime.h"

DateAndTime::DateAndTime()
{
}

vector<string> DateAndTime::GetFields(string dateTime)
{
	vector<string> fields;
	string day = "";
	day = day + dateTime[0] + dateTime[1];
	fields.push_back(day);

	string month = "";
	month = month + dateTime[3] + dateTime[4];
	fields.push_back(month);

	string year = "";
	year = year + dateTime[6] + dateTime[7] + dateTime[8] + dateTime[9];
	fields.push_back(year);

	string hour = "";
	hour = hour + dateTime[11] + dateTime[12];
	fields.push_back(hour);
	
	string minute = "";
	minute = minute + dateTime[14] + dateTime[15];
	fields.push_back(minute);
	
	string second = "";
	second = second + dateTime[17] + dateTime[18];
	fields.push_back(second);

	return fields;
}

string DateAndTime::ToString()
{
	return  to_string(Days)+"."+to_string(Months)+"."+to_string(Years);
}
