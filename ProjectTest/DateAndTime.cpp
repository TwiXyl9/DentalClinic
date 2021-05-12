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
	year = year + dateTime[6] + dateTime[7];
	fields.push_back(year);

	string hour = "";
	hour = hour + dateTime[9] + dateTime[10];
	fields.push_back(hour);
	
	string minute = "";
	minute = minute + dateTime[12] + dateTime[13];
	fields.push_back(minute);
	
	string second = "";
	second = second + dateTime[15] + dateTime[16];
	fields.push_back(second);

	return fields;
}

string DateAndTime::ToString()
{
	return  to_string(Days)+"."+to_string(Months)+"."+to_string(Years)+" "+to_string(Hours)+"."+to_string(Minutes)+"."+to_string(Seconds);
}
