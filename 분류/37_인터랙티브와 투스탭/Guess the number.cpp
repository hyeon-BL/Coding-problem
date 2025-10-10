#include <iostream>
using namespace std;

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    long long N;
    cin >> N;

    long long low = 1, high = N;
    while (low <= high)
    {
        long long guess = low + (high - low) / 2;
        cout << "? " << guess << endl;

        int response;
        cin >> response;

        if (response == 0)
        {
            // Correct guess
            cout << "= " << guess << endl;
            return 0;
        }
        else if (response == -1)
        {
            // The number is higher
            low = guess + 1;
        }
        else if (response == 1)
        {
            // The number is lower
            high = guess - 1;
        }
    }
    return 0;
}