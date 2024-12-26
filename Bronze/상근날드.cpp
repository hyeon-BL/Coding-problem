#include <iostream>
using namespace std;
int main()
{
    int b1, b2, b3, d1, d2;
    cin >> b1 >> b2 >> b3 >> d1 >> d2;
    cout << min(b1, min(b2, b3)) + min(d1, d2) - 50;
}