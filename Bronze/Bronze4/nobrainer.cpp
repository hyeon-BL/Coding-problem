#include <iostream>
using namespace std;

int main()
{
    int N;
    int a, b;
    cin >> N;
    while (N--)
    {
        cin >> a >> b;
        if (a >= b)
            cout << "MMM BRAINS\n";
        else
            cout << "NO BRAINS\n";
    }
}