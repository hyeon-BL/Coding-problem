#include <iostream>
#include <cstdio> // for fflush

using namespace std;

int main()
{
    long long low = 1, high = 1e9;
    int steps = 0;

    while (steps < 100)
    {
        long long x;
        if (!(cin >> x))
        {
            // No more input from judge, or invalid input
            break;
        }

        steps++;

        if (low == high && x == low)
        {
            cout << "=" << endl;
            fflush(stdout);
            break;
        }

        // Handle guesses outside the current valid range (unexpected but possible)
        if (x < low)
        {
            cout << ">" << endl;
        }
        else if (x > high)
        {
            cout << "<" << endl;
        }
        // To make the game longer, always keep the larger partition.
        else if ((high - x) > (x - low))
        {
            cout << ">" << endl;
            low = x + 1;
        }
        else
        {
            cout << "<" << endl;
            high = x - 1;
        }
        fflush(stdout);
    }

    return 0;
}
