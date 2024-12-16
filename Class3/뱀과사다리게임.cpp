#include<iostream>
#include<vector>
#include<queue>
#include<climits>
using namespace std;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);

    int N, M; // N: 사다리 수, M: 뱀의 수
    cin >> N >> M;

    vector<int> graph(101);
    for (int i = 1; i <= 100; i++) {
        graph[i] = i;
    }

    for (int i = 0; i < N; i++) {
        int x, y;
        cin >> x >> y;
        graph[x] = y;
    }
    for (int i = 0; i < M; i++) {
        int u, v;
        cin >> u >> v;
        graph[u] = v;
    }

    vector<int> dist(101, INT_MAX);
    dist[1] = 0;

    queue<int> q;
    q.push(1);

    while (!q.empty()) { // BFS
        int curr = q.front();
        q.pop();

        for (int dice = 1; dice <= 6; dice++) { // 주사위 1~6
            int next = curr + dice;
            if (next <= 100) {
                next = graph[next]; 
                if (dist[next] > dist[curr] + 1) {
                    dist[next] = dist[curr] + 1; // 최소 이동 횟수
                    q.push(next);
                }
            }
        }
    }

    cout << dist[100];
    return 0;
}