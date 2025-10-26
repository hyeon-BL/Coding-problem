#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    int N, M;
    cin >> N >> M;

    set<int> prices;
    vector<int> demands(M);
    for (int i = 0; i < M; i++)
    {
        int price;
        cin >> price;
        prices.insert(price);
        demands[i] = price;
    }
    sort(demands.begin(), demands.end(), greater<int>());

    int max_revenue = 0;
    int final_price = 0;
    for (int price : prices)
    {
        int revenue = 0, count = 0;
        for (int demand : demands)
        {
            if (demand >= price && count < N)
            {
                revenue += price;
                count++;
            }
            else
                break;
        }
        if (revenue > max_revenue)
        {
            max_revenue = revenue;
            final_price = price;
        }
    }
    cout << final_price << ' ' << max_revenue << '\n';
}