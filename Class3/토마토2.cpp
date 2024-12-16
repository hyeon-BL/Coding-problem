#include<iostream>
#include<vector>
#include<queue>
using namespace std;

struct Point {
    int n, m;
};

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);

    int M, N, H;
    cin >> M >> N;

    vector<vector<int>> A(N, vector<int>(M));
    queue<Point> q;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> A[i][j];
            if (A[i][j] == 1) {
                q.push({i, j});
            }
        }
    }

    int dn[] = {1, -1, 0, 0, 0, 0};
    int dm[] = {0, 0, 1, -1, 0, 0};

    int days = 0;

    // BFS
    while (!q.empty()) {
        int size = q.size();
        bool progressed = false;
        for (int i = 0; i < size; i++) {
            Point p = q.front(); // 토마토 위치
            q.pop();
            for (int dir = 0; dir < 4; dir++) { // 4방향(상하좌우) 탐색
                int nn = p.n + dn[dir];
                int nm = p.m + dm[dir];
                if (nn >= 0 && nn < N && nm >= 0 && nm < M && A[nn][nm] == 0) {
                    A[nn][nm] = 1;
                    q.push({nn, nm});
                    progressed = true;
                }
            }
        }
        if (progressed) days++;
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (A[i][j] == 0) {
                cout << -1;
                return 0;
            }
        }
    }

    cout << days;
    return 0;
}