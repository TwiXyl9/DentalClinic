#include "DateParser.h"

tm DateParser::ParseDate(string stringDate)
{
    string dayString = "";
    string monthString = "";
    string yearString = "";


    int i = 0;
    for (int i = 0; i < 2; i++)
    {
        dayString += stringDate[i];
    }
    i++;
    for (int i = 0; i < 2; i++)
    {
        monthString+= stringDate[i];
    }
    i++;
    for (int i = 0; i < stringDate.length(); i++)
    {
        yearString += stringDate[i];
    }

    tm date;
    date.tm_year = stoi(yearString);
    date.tm_mon = stoi(monthString);
    date.tm_mday = stoi(dayString);

    return date;
}
