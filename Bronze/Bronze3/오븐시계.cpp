#include <iostream>
using namespace std;

int main()
{
    int A, B, C;
    cin >> A >> B;
    cin >> C;

    int result_time = A * 60 + B + C;
    int result_hour = result_time / 60;
    int result_minute = result_time % 60;
    if (result_hour >= 24)
    {
        result_hour -= 24;
    }
    cout << result_hour << " " << result_minute;
}