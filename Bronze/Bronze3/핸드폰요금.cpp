#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int N;
    cin >> N;

    vector<int> v(N);
    for (int i = 0; i < N; i++)
    {
        cin >> v[i];
    }

    int Y, M;
    Y = M = 0;
    for (int i = 0; i < N; i++)
    {
        Y += (v[i] / 30 + 1) * 10;
        M += (v[i] / 60 + 1) * 15;
    }
    if (Y < M)
    {
        cout << "Y " << Y;
    }
    else if (Y > M)
    {
        cout << "M " << M;
    }
    else
    {
        cout << "Y M " << Y;
    }
}