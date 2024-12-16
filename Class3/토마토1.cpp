#include<iostream>
#include<vector>
#include<queue>
using namespace std;

struct Point {
    int h, n, m;
};

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);

    int M, N, H;
    cin >> M >> N >> H;

    vector<vector<vector<int>>> A(H, vector<vector<int>>(N, vector<int>(M)));
    queue<Point> q;
    for (int h = 0; h < H; h++) {
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                cin >> A[h][i][j];
                if (A[h][i][j] == 1) {
                    q.push({h, i, j});
                }
            }
        }
    }

    int dh[] = {1, -1, 0, 0, 0, 0};
    int dn[] = {0, 0, 1, -1, 0, 0};
    int dm[] = {0, 0, 0, 0, 1, -1};

    int days = 0;

    // BFS
    while (!q.empty()) {
        int size = q.size();
        bool progressed = false;
        for (int i = 0; i < size; i++) {
            Point p = q.front(); // 토마토 위치
            q.pop();
            for (int dir = 0; dir < 6; dir++) { // 6방향 탐색
                int nh = p.h + dh[dir];
                int nn = p.n + dn[dir];
                int nm = p.m + dm[dir];
                if (nh >= 0 && nh < H && nn >= 0 && nn < N && nm >= 0 && nm < M && A[nh][nn][nm] == 0) {
                    A[nh][nn][nm] = 1;
                    q.push({nh, nn, nm});
                    progressed = true;
                }
            }
        }
        if (progressed) days++;
    }

    for (int h = 0; h < H; h++) {
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                if (A[h][i][j] == 0) {
                    cout << -1;
                    return 0;
                }
            }
        }
    }

    cout << days;
    return 0;
}