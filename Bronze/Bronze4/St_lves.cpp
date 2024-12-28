#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    double input, output = 0;
    while (true)
    {
        cin >> input;
        if (input == 0)
            break;

        for (int i = 0; i < 5; i++)
        {
            output += pow(input, i);
        }
        output = round(output * 100) / 100;
        cout << fixed << setprecision(2) << output << '\n';
        output = 0;
    }
}