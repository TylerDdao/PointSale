#include "React.h"

bool IsButtonClicked(Rectangle rec, int key) {
	if (CheckCollisionPointRec(GetMousePosition(), rec)) {
		if (IsMouseButtonPressed(key)) {
			return true;
		}
	}
}

bool MonthHas31Days(int month)
{
		if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12) {
			return true;
		}
		else {
			return false;
		}
}

bool IsLaterThanToday(int day, int month, int year)
{
	int currentDay = ExtractDay(GetCurrentDateTime());
	int currentMonth = ExtractMonth(GetCurrentDateTime());
	int currentYear = ExtractYear(GetCurrentDateTime());
	if (year < currentYear) {
		return false;
	}
	else if (year == currentYear){
		if (month < currentMonth) {
			return false;
		}
		else if (month == currentMonth) {
			if (day <= currentDay) {
				return false;
			}
			else {
				return true;
			}
		}
		else {
			return false;
		}
	}
	else {
		return true;
	}
}
