#include <iostream>
using namespace std;

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    int N;
    cin >> N;
    int cnt = N + 1;
    while (N--)
    {
        cout << --cnt << '\n';
    }
}