#include <iostream>
#include <vector>
using namespace std;

pair<bool, vector<int>> is_perfect(int n)
{
    int sum = 0;
    vector<int> divisors;
    for (int i = 1; i <= n / 2; i++)
    {
        if (n % i == 0)
        {
            sum += i;
            divisors.push_back(i);
        }
    }
    return {sum == n, divisors};
}

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    while (true)
    {
        int n;
        cin >> n;
        if (n == -1)
            break;
        pair<bool, vector<int>> result = is_perfect(n);
        if (result.first)
        {
            cout << n << " = ";
            for (size_t i = 0; i < result.second.size(); i++)
            {
                cout << result.second[i];
                if (i != result.second.size() - 1)
                {
                    cout << " + ";
                }
            }
        }
        else
        {
            cout << n << " is NOT perfect.";
        }
        cout << '\n';
    }
}