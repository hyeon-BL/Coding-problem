#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    while (true)
    {
        double input, output = 0;
        cin >> input;
        if (input < 0)
            break;
        output = round(input * 100 * 0.167) / 100;
        cout << "Objects weighing " << fixed << setprecision(2) << input << " on Earth will weigh " << fixed << setprecision(2) << output << " on the moon.\n";
    }
}