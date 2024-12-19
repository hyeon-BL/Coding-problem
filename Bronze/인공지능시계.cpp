#include <iostream>
using namespace std;

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    int hour, minute, second;
    int time;
    cin >> hour >> minute >> second;
    cin >> time;

    hour += time / 3600;
    time %= 3600;
    minute += time / 60;
    time %= 60;
    second += time;

    minute += second / 60;
    second %= 60;
    hour += minute / 60;
    minute %= 60;
    hour %= 24;

    cout << hour << ' ' << minute << ' ' << second;
}