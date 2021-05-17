#include "DateAndTime.h"

DateAndTime::DateAndTime()
{
}

vector<string> DateAndTime::GetDateFields(string dateTime)
{
	vector<string> fields;

	string field = "";

	for (int i = 0; ; i++)
	{
		if (dateTime[i] == '.')
		{
			fields.push_back(field);
			field = "";
			continue;
		}
		else if(dateTime[i] == '\0')
		{
			fields.push_back(field);
			field = "";
			break;
		}
		field += dateTime[i];
	}

	return fields;
}

vector<string> DateAndTime::GetDateAndTimeFields(string dateTime)
{
	vector<string> fields;

	string field = "";

	for (int i = 0; ; i++)
	{
		if (dateTime[i] == '.' || dateTime[i] == ' ')
		{
			fields.push_back(field);
			field = "";
			continue;
		}
		else if (dateTime[i] == '\0')
		{
			fields.push_back(field);
			field = "";
			break;
		}
		field += dateTime[i];
	}

	return fields;
}

DateAndTime DateAndTime::ToDateAndTime(System::DateTime dateTime) {
	DateAndTime date;
	date.Days = dateTime.Day;
	date.Months = dateTime.Month;
	date.Years = dateTime.Year;
	date.Hours = dateTime.Hour;
	date.Minutes = dateTime.Minute;
	date.Seconds = dateTime.Second;
	return date;
}
string DateAndTime::ToString()
{
	return  to_string(Days)+"."+to_string(Months)+"."+to_string(Years);
}
