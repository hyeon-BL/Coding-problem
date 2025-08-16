#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];

    int target;
    cin >> target;

    int left = 0, right = n - 1, count = 0;
    sort(a.begin(), a.end()); // 정렬 to use two-pointer technique
    while (left < right)
    {
        int sum = a[left] + a[right];
        if (sum == target)
            count++;
        if (sum < target)
            left++;
        else
            right--;
    }
    cout << count << "\n";
}