#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    int N;
    cin >> N;

    priority_queue<int, vector<int>, greater<int>> pq;
    for (int i = 0; i < N * N; i++)
    {
        int x;
        cin >> x;
        pq.push(x);

        if (pq.size() > N)
        { // N개를 초과하는 경우 - 가장 작은 값을 제거
            pq.pop();
        }
    }
    cout << pq.top() << "\n";
}