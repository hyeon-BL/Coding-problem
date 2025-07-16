#include <iostream>
using namespace std;

int cnt_recursion = 1;
int cnt_dynamic = 0;

int fib(int n)
{
    if (n == 1 || n == 2)
        return 1;
    cnt_recursion++;
    return fib(n - 1) + fib(n - 2);
}

int fibonacci(int n)
{

    int fib[100] = {0};
    fib[1] = 1;
    fib[2] = 1;
    for (int i = 3; i <= n; i++)
    {
        fib[i] = fib[i - 1] + fib[i - 2];
        cnt_dynamic++;
    }
    return fib[n];
}

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    int n;
    cin >> n;

    int result_recursion = fib(n);
    int result_dynamic = fibonacci(n);
    cout << cnt_recursion << " " << cnt_dynamic << "\n";
}