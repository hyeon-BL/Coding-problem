#include <iostream>
#include <queue>
using namespace std;

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    int T, M;
    cin >> T;
    while (T--)
    {
        cin >> M;
        priority_queue<int> max_pq;                            // 최대 힙
        priority_queue<int, vector<int>, greater<int>> min_pq; // 최소 힙

        cout << M / 2 + 1 << '\n'; // 중앙값의 개수 출력
        for (int i = 1; i <= M; i++)
        {
            int x;
            cin >> x;
            max_pq.push(x);

            if (i % 2 == 1)
            { // 홀수번째 입력일 때
                min_pq.push(max_pq.top());
                max_pq.pop();
                cout << min_pq.top() << ' '; // 중앙값 출력
            }
            else
            { // 짝수번째 입력일 때
                min_pq.push(max_pq.top());
                max_pq.pop();
                max_pq.push(min_pq.top());
                min_pq.pop();
            }
        }
        cout << '\n';
    }
}