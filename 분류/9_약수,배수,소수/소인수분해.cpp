#include <iostream>
#include <vector>
using namespace std;

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    int N, temp; // 1 <= N <= 10,000,000
    cin >> N;
    temp = N; // original N

    vector<int> results;
    for (int i = 2; i <= temp / 2; i++)
    {
        while (N % i == 0)
        {
            results.push_back(i);
            N /= i;
        }
    }
    for (int i = 0; i < results.size(); i++)
    {
        cout << results[i] << '\n';
    }
    if (results.size() == 0 && N != 1)
    {
        cout << N << '\n';
    }
}