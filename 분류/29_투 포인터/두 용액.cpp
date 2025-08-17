#include <iostream>
#include <algorithm>
#include <vector>
#include <climits>
using namespace std;

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    int N;
    cin >> N;

    vector<int> liquids(N);
    for (int i = 0; i < N; i++)
    {
        cin >> liquids[i];
    }

    sort(liquids.begin(), liquids.end());

    int left = 0;
    int right = N - 1;
    int min_diff = INT_MAX;
    pair<int, int> closest_pair;

    while (left < right)
    {
        int sum = liquids[left] + liquids[right];
        if (abs(sum) < min_diff)
        {
            min_diff = abs(sum);
            closest_pair = {liquids[left], liquids[right]};
        }

        if (sum < 0)
            left++;

        else if (sum > 0)
            right--;

        else
            break;
    }

    cout << closest_pair.first << " " << closest_pair.second;
}