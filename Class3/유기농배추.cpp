#include<iostream>
using namespace std;

int dfs(int** field, int x, int y, int M, int N) {
    if (x < 0 || x >= M || y < 0 || y >= N) return 0;
    if (field[x][y] == 0) return 0;
    field[x][y] = 0; // 방문한 배추는 0으로 초기화 -> 다시 방문하지 않기 위함
    dfs(field, x - 1, y, M, N);
    dfs(field, x + 1, y, M, N);
    dfs(field, x, y - 1, M, N);
    dfs(field, x, y + 1, M, N);
    return 1;
}


int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);

    int T;
    cin >> T;
    while (T--) {
        int M, N, K;
        cin >> M >> N >> K; // M: 세로, N: 가로, K: 배추 수
        int** field = new int*[M];
        for (int i = 0; i < M; i++) {
            field[i] = new int[N];
            fill(field[i], field[i] + N, 0); // 0으로 초기화
        }
        for (int i = 0; i < K; i++) {
            int x, y;
            cin >> x >> y;
            field[x][y] = 1;
        }
        int result = 0;
        for (int i = 0; i < M; i++) { // O(MN)
            for (int j = 0; j < N; j++) {
                result += dfs(field, i, j, M, N);
            }
        }
        cout << result << '\n';
    }
}