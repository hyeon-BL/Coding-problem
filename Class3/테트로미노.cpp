#include <iostream>
#include <algorithm>
using namespace std;

int n, m, ans;
int paper[555][555];
bool visited[555][555]; // visited[i][j]: (i, j)를 방문했는지 여부 -> avoid repeated visit
int dy[4] = {1, 0, -1, 0};
int dx[4] = {0, 1, 0, -1};

void dfs(int y, int x, int cnt, int val) {
    if (cnt == 4) {
        ans = max(ans, val);
    }
    else {
        for (int i = 0; i < 4; i++) {
            int ny = y + dy[i];
            int nx = x + dx[i];
            if (ny < 1 || ny > n || nx < 1 || nx > m) continue;
            if (visited[ny][nx]) continue;
            visited[ny][nx] = true;
            dfs(ny, nx, cnt + 1, val + paper[ny][nx]);
            visited[ny][nx] = false;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m;
    for (int i = 1; i <= n; ++i) // graph input
        for (int j = 1; j <= m; ++j)
            cin >> paper[i][j];

    for (int i = 1; i <= n; ++i) { // dfs로 찾을 수 있는 모든 모양 탐색
        for (int j = 1; j <= m; ++j) {
            visited[i][j] = true;
            dfs(i, j, 1, paper[i][j]);
            visited[i][j] = false;
        }
    }

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            int t = paper[i][j]; // 중앙 블록
            int mini = 1001;
            for (int k = 0; k < 4; k++) { // ㅗ ㅏ ㅜ ㅓ 모양 탐색
                int ny = i + dy[k];
                int nx = j + dx[k];
                mini = min(mini, paper[ny][nx]);
                t += paper[ny][nx]; // ㅗ ㅏ ㅜ ㅓ 모양의 합
            } 
            if (t - mini > ans) ans = t - mini; // 기존 가장 작은 블록 제거거
        }
    }

    cout << ans;
    return 0;
}