#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void SubsetSums(const vector<long long> &arr, vector<long long> &subsetSum, int start, int end)
{
    int n = end - start + 1;
    for (int i = 0; i < (1 << n); i++)
    { // 2^n subsets
        long long sum = 0;
        for (int j = 0; j < n; j++)
        {
            if (i & (1 << j))
            { // If j-th element is included
                sum += arr[start + j];
            }
        }
        subsetSum.push_back(sum);
    }
}

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    int N, C;
    cin >> N >> C;

    vector<long long> things(N);
    for (int i = 0; i < N; i++)
        cin >> things[i];

    vector<long long> leftSubset, rightSubset;
    SubsetSums(things, leftSubset, 0, N / 2 - 1);
    SubsetSums(things, rightSubset, N / 2, N - 1);

    sort(rightSubset.begin(), rightSubset.end());

    long long count = 0;
    for (long long sum : leftSubset)
    { // Binary search to find the lower value than C - sum
        count += upper_bound(rightSubset.begin(), rightSubset.end(), C - sum) - rightSubset.begin();
    }
    cout << count << "\n";
}