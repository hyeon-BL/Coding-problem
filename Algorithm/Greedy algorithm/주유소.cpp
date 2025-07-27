#include <iostream>
#include <vector>
using namespace std;

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    int N;
    cin >> N;
    vector<int> distance(N - 1);
    vector<int> price(N);
    for (int i = 0; i < N - 1; i++)
    {
        cin >> distance[i];
    }
    for (int i = 0; i < N; i++)
    {
        cin >> price[i];
    }

    long long totalCost = 0;
    long long currentPrice = price[0];
    for (int i = 0; i < N - 1; i++)
    {
        totalCost += currentPrice * distance[i];
        if (currentPrice > price[i + 1])
            currentPrice = price[i + 1];
    }
    cout << totalCost << '\n';
}