#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

pair<int, int> approximated_solution(int N, vector<int> &solutions)
{ // 두 포인터를 이용한 풀이
    int left = 0, right = N - 1;
    int min_diff = 2000000000;
    pair<int, int> answer;

    while (left < right)
    { // 두 포인터가 만날 때까지
        int sum = solutions[left] + solutions[right];
        int diff = abs(sum);

        if (diff < min_diff)
        { // 더 작은 차이가 나오면 갱신
            min_diff = diff;
            answer = {solutions[left], solutions[right]};
        }

        if (sum < 0)
        { // 음수인 경우(더 큰 수가 필요)
            left++;
        }
        else
        { // 양수인 경우(더 작은 수가 필요)
            right--;
        }
    }

    return answer;
}

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    int N;
    cin >> N;
    vector<int> solutions(N);
    for (int i = 0; i < N; i++)
    {
        cin >> solutions[i];
    }

    pair<int, int> result = approximated_solution(N, solutions);
    cout << result.first << " " << result.second;

    return 0;
}