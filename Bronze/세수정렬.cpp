#include <iostream>
using namespace std;

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    int A, B, C;
    cin >> A >> B >> C;

    if (A > B)
    {
        if (A > C)
        {
            if (B > C)
            {
                cout << C << ' ' << B << ' ' << A;
            }
            else
            {
                cout << B << ' ' << C << ' ' << A;
            }
        }
        else
        {
            cout << B << ' ' << A << ' ' << C;
        }
    }
    else
    {
        if (B > C)
        {
            if (A > C)
            {
                cout << C << ' ' << A << ' ' << B;
            }
            else
            {
                cout << A << ' ' << C << ' ' << B;
            }
        }
        else
        {
            cout << A << ' ' << B << ' ' << C;
        }
    }
}