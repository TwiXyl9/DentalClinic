#include "DateTime.h"

DateTime::DateTime()
{
}

vector<string> DateTime::GetFields(string dateTime)
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

string DateTime::ToString()
{
	return  to_string(Days)+"."+to_string(Months)+"."+to_string(Years)+" "+to_string(Hours)+"."+to_string(Minutes)+"."+to_string(Seconds);
}
