#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    int N;
    cin >> N;
    vector<int> A(N);
    for (int i = 0; i < N; i++)
    {
        cin >> A[i];
    }

    vector<int> lis;
    for (int i = 0; i < N; i++)
    {                                                        // Longest Increasing Subsequence
        auto it = lower_bound(lis.begin(), lis.end(), A[i]); // A[i]보다 크거나 같은 값이 처음 나오는 위치
        if (it == lis.end())
        { // 마지막에 나온다면
            lis.push_back(A[i]);
        }
        else
        { // 그렇지 않다면
            *it = A[i];
        }
    }

    cout << lis.size();
}

/*
dp 풀이법 (시간복잡도 O(N^2)) -> 시간초과
    vector<int> dp(N, 1);
    for (int i = 0; i < N; i++)
    { // 가장 긴 증가하는 부분 수열
        for (int j = 0; j < i; j++)
        { // i번째 수열보다 작은 수열 중 가장 긴 수열 찾기
            if (A[i] > A[j])
            { // i번째 수열이 j번째 수열보다 크다면
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
    }
*/