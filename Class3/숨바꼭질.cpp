#include<iostream>
#include<queue>
using namespace std;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);

    int N, K;
    cin >> N >> K;

    if (N >= K) { // N이 K보다 크거나 같으면 -1로만 이동하면 됨
        cout << N - K;
        return 0;
    }

    queue<pair<int, int>> q;
    q.push({N, 0});
    bool visited[100001] = {false};
    visited[N] = true;

    while (!q.empty()) {
        int cur = q.front().first;
        int cnt = q.front().second;
        q.pop();

        if (cur == K) {
            cout << cnt << '\n';
            return 0;
        }

        if (cur * 2 <= 100000 && !visited[cur * 2]) { // 2배로 이동
            q.push({cur * 2, cnt + 1});
            visited[cur * 2] = true;
        }
        if (cur + 1 <= 100000 && !visited[cur + 1]) { // +1로 이동
            q.push({cur + 1, cnt + 1});
            visited[cur + 1] = true;
        }
        if (cur - 1 >= 0 && !visited[cur - 1]) { // -1로 이동
            q.push({cur - 1, cnt + 1});
            visited[cur - 1] = true;
        }
    }
}