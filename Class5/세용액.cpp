#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    int N;
    cin >> N;
    vector<long long> solutions(N);
    for (int i = 0; i < N; i++)
    {
        cin >> solutions[i];
    }

    sort(solutions.begin(), solutions.end()); // 오름차순 정렬(NlogN)

    long long closestSum = LLONG_MAX;
    int result[3];

    for (int i = 0; i < N - 2; i++)
    {
        int left = i + 1;  // i보다 큰 인덱스
        int right = N - 1; // 마지막 인덱스

        while (left < right)
        { // 투 포인터
            long long sum = solutions[i] + solutions[left] + solutions[right];

            if (abs(sum) < abs(closestSum))
            { // 절댓값 비교 후 갱신
                closestSum = sum;
                result[0] = solutions[i];
                result[1] = solutions[left];
                result[2] = solutions[right];
            }

            if (sum < 0)
            { // 음수인 경우 left 증가
                left++;
            }
            else
            { // 양수인 경우 right 감소
                right--;
            }
        }
    }

    cout << result[0] << " " << result[1] << " " << result[2];
}