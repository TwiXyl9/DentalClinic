#include "DateTime.h"

DateTime::DateTime()
{
}

string* DateTime::GetFields(string dateTime)
{
	string fields[6];
	fields[0] = dateTime[0] + dateTime[1];
	fields[1] = dateTime[3] + dateTime[4];
	fields[2] = dateTime[6] + dateTime[7];
	fields[3] = dateTime[9] + dateTime[10];
	fields[4] = dateTime[12] + dateTime[13];
	fields[5] = dateTime[15] + dateTime[16];

	return fields;
}

string DateTime::ToString()
{
	return  to_string(Days)+"."+to_string(Months)+"."+to_string(Years)+" "+to_string(Hours)+"."+to_string(Minutes)+"."+to_string(Seconds);
}
