#include "Date.h"

		Date::Date() {};
		Date::Date(int day, int month, int year) {
			this->day = day;
			this->month = month;
			this->year = year;
		};
		void Date::setDay(int d) {
			if (d < 31 && d > 0)
				day = d;
		}
		int Date::getDay() {
			return day;
		}
		void Date::setMonth(int m) {
			if (m < 13 && m> 0)
				month = m;
		}
		int Date::getMonth() {
			return month;
		}
		void Date::setYear(int y) {
			if (y < 2022 && y > 1900)
				year = y;
		}
		int Date::getYear() {
			return year;
		}

