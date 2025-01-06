#include <iostream>
#include <string>
using namespace std;

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    string A, B;
    cin >> A >> B;

    long long result = 0;
    for (char &c : A)
    {
        for (char &d : B)
        {
            result += (c - '0') * (d - '0');
        }
    }

    cout << result;
}