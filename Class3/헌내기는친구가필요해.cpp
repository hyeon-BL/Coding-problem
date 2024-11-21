#include<iostream>
#include<cassert>
using namespace std;

bool isValid(int x, int y, int N, int M, char** arr, bool** visited) {
    return (x >= 0 && x < N && y >= 0 && y < M && arr[x][y] != 'X' && !visited[x][y]);
}

int dfs(int x, int y, int N, int M, char** arr, bool** visited) {
    if (!isValid(x, y, N, M, arr, visited)) return 0;
    visited[x][y] = true;
    int count = (arr[x][y] == 'P') ? 1 : 0; // P면 1, 아니면 0
    int dx[] = {1, -1, 0, 0};
    int dy[] = {0, 0, 1, -1};
    for (int i = 0; i < 4; ++i) {
        count += dfs(x + dx[i], y + dy[i], N, M, arr, visited); // 상하좌우
    }
    return count;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);

    int N, M;
    cin >> N >> M;

    assert(N > 0 && M > 0); // Ensure N and M are positive

    char** arr = new char*[N];
    for (int i = 0; i < N; i++) {
        arr[i] = new char[M];
        for (int j = 0; j < M; j++) {
            cin >> arr[i][j]; // Read each character individually
        }
    }

    bool** visited = new bool*[N];
    for (int i = 0; i < N; ++i) {
        visited[i] = new bool[M]();
    }

    int startX = -1, startY = -1;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            if (arr[i][j] == 'I') { // 시작점
                startX = i;
                startY = j;
                break;
            }
        }
    }

    assert("TT"); // Ensure 'I' is found

    int result = dfs(startX, startY, N, M, arr, visited);
    if (result == 0) {
        cout << "TT" << endl;
    } else {
        cout << result << endl;
    }

    for (int i = 0; i < N; ++i) {
        delete[] arr[i];
        delete[] visited[i];
    }
    delete[] arr;
    delete[] visited;

    return 0;
}