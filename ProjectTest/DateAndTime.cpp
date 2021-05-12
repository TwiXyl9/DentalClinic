#include "DateAndTime.h"

DateAndTime::DateAndTime()
{
}

vector<string> DateAndTime::GetFields(string dateTime)
{
	vector<string> fields;
	fields.push_back(to_string(dateTime[0]) + to_string(dateTime[1]));
	fields.push_back(to_string(dateTime[3]) + to_string(dateTime[4]));
	fields.push_back(to_string(dateTime[6]) + to_string(dateTime[7]));
	fields.push_back(to_string(dateTime[9]) + to_string(dateTime[10]));
	fields.push_back(to_string(dateTime[12]) + to_string(dateTime[13]));
	fields.push_back(to_string(dateTime[15]) + to_string(dateTime[16]));

	return fields;
}

string DateAndTime::ToString()
{
	return  to_string(Days)+"."+to_string(Months)+"."+to_string(Years)+" "+to_string(Hours)+"."+to_string(Minutes)+"."+to_string(Seconds);
}
