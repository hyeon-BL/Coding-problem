#include<iostream>
#include<string>
#include<iomanip>
using namespace std;

bool Is_leap(int Y) {
	if ((Y % 4 == 0 && Y % 100 != 0) || Y % 400 == 0) return true;
	return false;
}

int days_in_month[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

int get_month_index(string month) {
    if (month == "January") return 0;
    if (month == "February") return 1;
    if (month == "March") return 2;
    if (month == "April") return 3;
    if (month == "May") return 4;
    if (month == "June") return 5;
    if (month == "July") return 6;
    if (month == "August") return 7;
    if (month == "September") return 8;
    if (month == "October") return 9;
    if (month == "November") return 10;
    if (month == "December") return 11;
    return -1;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);

    string month, day, time;
    int year;
    cin >> month >> day >> year >> time;

    int month_index = get_month_index(month);
    int day_of_month = stoi(day.substr(0, day.size() - 1));
    int hour = stoi(time.substr(0, 2));
    int minute = stoi(time.substr(3, 2));

    if (Is_leap(year)) days_in_month[1] = 29;

    int days_passed = 0;
    for (int i = 0; i < month_index; ++i) {
        days_passed += days_in_month[i];
    }
    days_passed += day_of_month - 1;

    int total_minutes_passed = days_passed * 24 * 60 + hour * 60 + minute;
    int total_minutes_in_year = (Is_leap(year) ? 366 : 365) * 24 * 60;

    double percentage = (double)total_minutes_passed / total_minutes_in_year * 100;

    cout << fixed << setprecision(9) << percentage << endl;

    return 0;
}