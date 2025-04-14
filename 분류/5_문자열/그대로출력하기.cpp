#include <iostream>
using namespace std;

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    while (true)
    {
        string row;
        getline(cin, row);

        if (cin.eof())
            break; // End of input

        cout << row << '\n';
    }
}