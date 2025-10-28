#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    int N;
    cin >> N;
    map<int, bool> num_arr;
    vector<int> nums(N);
    for (int i = 0; i < N; i++)
    {
        int num;
        cin >> num;
        num_arr[num] = true;
        nums[i] = num;
    }
    sort(nums.begin(), nums.end());
    int min_missing = 5;
    for (const int &num : nums)
    {
        int missing_count = 0;
        for (int i = 0; i < 5; i++)
        {
            if (!num_arr[num + i])
                missing_count++;
        }
        min_missing = min(min_missing, missing_count);
    }
    cout << min_missing << endl;
    return 0;
}