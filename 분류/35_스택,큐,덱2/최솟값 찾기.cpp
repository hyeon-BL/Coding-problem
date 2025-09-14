#include <iostream>
#include <vector>
#include <deque>
using namespace std;

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    int N, L;
    cin >> N >> L;
    vector<int> arr(N);
    for (int i = 0; i < N; i++)
        cin >> arr[i];

    deque<int> dq; // i-L+1 ~ i 범위의 인덱스 저장
    vector<int> result;
    for (int i = 0; i < N; i++)
    {
        // 범위에서 벗어난 값 제거
        if (!dq.empty() && dq.front() == i - L)
            dq.pop_front();

        // 현재 값보다 크거나 같은 값 제거
        while (!dq.empty() && arr[dq.back()] >= arr[i])
            dq.pop_back();

        dq.push_back(i);
        result.push_back(arr[dq.front()]);
    }

    for (int i = 0; i < result.size(); i++)
        cout << result[i] << ' ';

    return 0;
}