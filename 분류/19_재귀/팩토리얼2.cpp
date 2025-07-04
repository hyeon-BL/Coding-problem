#include <iostream>
using namespace std;

long long factorial(long long n)
{
    if (n == 0 || n == 1)
        return 1;
    return n * factorial(n - 1);
}

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    int N;
    cin >> N;
    cout << factorial(N) << '\n';
    return 0;
}