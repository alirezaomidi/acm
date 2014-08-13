#include <iostream>
using namespace std;

int main() {
	int monthDaysCount[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	int day, month;
	cin >> day >> month;

	if (month <= 0 || month > 12 || day <= 0 || day > monthDaysCount[month - 1]) {
		cout << "Impossible" << endl;
		return 0;
	}

	int days = 0;
	for (int currentMonth = 0; currentMonth < month - 1; ++currentMonth)
		days += monthDaysCount[currentMonth];
	days += day;

	cout << ((days %= 7) ? days : 7) << endl;

	return 0;
}
