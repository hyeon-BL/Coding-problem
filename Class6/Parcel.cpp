#include <iostream>
#include <vector>
using namespace std;

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    int w, n; // w: 목표 무게, n: 물건의 개수
    cin >> w >> n;
    vector<int> weight(n);
    for (int i = 0; i < n; i++)
    {
        cin >> weight[i];
    }

    vector<int> DP1(444'444, -1);
    vector<int> DP2(444'444, -1);

    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            int weightSum = weight[i] + weight[j];
            if (DP1[weightSum] == -1)
            {
                DP1[weightSum] = i;
                DP2[weightSum] = j;
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            int weightSum = w - (weight[i] + weight[j]);
            if (weightSum > 400'000 || weightSum < 0 || DP1[weightSum] < 0)
                continue;
            int a = DP1[weightSum];
            int b = DP2[weightSum];
            if (a != i && a != j && b != i && b != j)
            {
                cout << "YES";
                return 0;
            }
        }
    }

    cout << "NO"; // 출력 조건을 잘 보자
    return 0;
}

// 1% 틀림??...

// #include <iostream>
// #include <vector>
// #include <algorithm>
// using namespace std;

// // 두 부분 집합의 합을 계산
// void calculateSubsetSums(const vector<int> &arr, vector<pair<int, int>> &subsetSums)
// {
//     int n = arr.size();
//     for (int i = 0; i < (1 << n); i++)
//     { // 모든 부분 집합 탐색
//         int sum = 0;
//         int num1 = i;
//         int count = 0;
//         while (num1 > 0)
//         {
//             if (num1 & 1)
//             {
//                 count++;
//             }
//             num1 >>= 1;
//         }
//         for (int j = 0; j < n; j++)
//         {
//             if (i & (1 << j))
//             { // j번째 원소가 부분 집합에 포함되면
//                 sum += arr[j];
//             }
//         }
//         subsetSums.push_back({sum, count}); // 부분 집합의 합과 원소 개수 저장
//     }
// }

// int main()
// {
//     int w, n; // w: 목표 무게, n: 물건의 개수
//     cin >> w >> n;
//     vector<int> weight(n);

//     for (int i = 0; i < n; i++)
//     {
//         cin >> weight[i];
//     }

//     // 물건을 두 그룹으로 나누기
//     int mid = n / 2;
//     vector<int> left(weight.begin(), weight.begin() + mid);
//     vector<int> right(weight.begin() + mid, weight.end());

//     // 두 그룹의 부분 집합 합 계산
//     vector<pair<int, int>> leftSums, rightSums;
//     calculateSubsetSums(left, leftSums);
//     calculateSubsetSums(right, rightSums);

//     // 오른쪽 부분 집합 합을 정렬
//     sort(rightSums.begin(), rightSums.end());

//     // 왼쪽 부분 집합 합과 오른쪽 부분 집합 합을 이용해 목표 무게 w를 찾기
//     for (auto leftSum : leftSums)
//     {
//         int target = w - leftSum.first;
//         int leftsecond = leftSum.second;
//         // 이진 탐색을 통해 오른쪽 부분 집합에서 목표 무게를 찾기
//         auto it = lower_bound(rightSums.begin(), rightSums.end(), make_pair(target, 0));
//         if (it != rightSums.end() && it->first == target && it->second + leftsecond == 4)
//         { // 오른쪽 부분 집합에서 목표 무게를 찾고, 두 부분 집합의 원소 개수가 4인지 확인
//             cout << "YES";
//             return 0;
//         }
//     }

//     cout << "NO";
//     return 0;
// }

// 시간초과: O(4*n*w)

// #include <iostream>
// #include <vector>
// using namespace std;

// int main()
// {
//     int w, n; // w: 목표 무게, n: 물건의 개수
//     cin >> w >> n;
//     vector<int> weight(n);

//     for (int i = 0; i < n; i++)
//     {
//         cin >> weight[i];
//     }

//     // DP 테이블 초기화
//     // dp[j][k]는 j 무게를 만들기 위해 k개의 물건을 사용했는지를 나타냄
//     vector<vector<bool>> dp(w + 1, vector<bool>(5, false));
//     dp[0][0] = true; // base case: 0 무게는 0개의 물건으로 만들 수 있음

//     // 부모 테이블 초기화
//     // parent[j][k]는 j 무게를 만들기 위해 k개의 물건을 사용했을 때, 이전 상태를 저장
//     vector<vector<pair<int, int>>> parent(w + 1, vector<pair<int, int>>(5, {-1, -1}));

//     for (int i = 0; i < n; i++)
//     {
//         for (int j = w; j >= weight[i]; j--)
//         {
//             for (int k = 4; k >= 1; k--)
//             {
//                 if (dp[j - weight[i]][k - 1])
//                 { // k-1개의 물건으로 j-weight[i] 무게를 만들 수 있다면
//                     dp[j][k] = true;
//                     parent[j][k] = {j - weight[i], k - 1};
//                 }
//             }
//         }
//     }

//     if (dp[w][4])
//     {
//         cout << "Yes\n";
//     }
//     else
//     {
//         cout << "No\n";
//     }

//     return 0;
// }