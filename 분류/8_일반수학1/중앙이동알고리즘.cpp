#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    int N;
    cin >> N;

    int dots = 2;
    for (int i = 0; i < N; i++)
    {
        dots += pow(2, i);
    }
    cout << dots * dots;
}