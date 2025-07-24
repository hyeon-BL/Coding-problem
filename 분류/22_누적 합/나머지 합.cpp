#include <iostream>
#include <vector>
using namespace std;

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    int N, M;
    cin >> N >> M;

    vector<int> remainder_count(M, 0); // 나머지의 빈도수 저장
    remainder_count[0] = 1;            // 초기값

    int cumulative_sum = 0;
    long long count = 0; // 결과를 저장 (부분 배열의 개수)

    for (int i = 0; i < N; i++)
    {
        int x;
        cin >> x;

        // 누적 합 계산
        cumulative_sum = (cumulative_sum + x) % M;

        // 현재 나머지가 이전에 등장한 횟수만큼 부분 배열이 조건을 만족
        // 1. 나머지가 0인 경우는 전체 배열이 조건을 만족
        // 2. 나머지가 0이 아닌 경우, 같은 나머지를 가진 구간이 조건을 만족
        count += remainder_count[cumulative_sum];

        // 현재 나머지의 빈도수 증가
        remainder_count[cumulative_sum]++;
    }

    cout << count << "\n";
    return 0;
}

/* 시간초과
   시간복잡도: O(N^2)
   공간복잡도: O(N)
   N <= 100,000 이므로 O(N^2) 시간복잡도는 불가능

#include <iostream>
#include <vector>
using namespace std;

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    int N, M;
    cin >> N >> M;

    vector<int> cumulative_sum(N + 1, 0);
    for (int i = 1; i <= N; i++)
    {
        int x;
        cin >> x;
        cumulative_sum[i] = (cumulative_sum[i - 1] + x) % M;
    }

    int count = 0;
    for (int i = 1; i <= N; i++)
    {
        for (int j = i; j <= N; j++)
        {
            int subarray_sum = (cumulative_sum[j] - cumulative_sum[i - 1] + M) % M;
            if (subarray_sum == 0)
                count++;
        }
    }
    cout << count << "\n";
    return 0;
}

*/