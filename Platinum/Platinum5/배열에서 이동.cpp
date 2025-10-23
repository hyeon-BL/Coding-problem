#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<set>

using namespace std;

int n;
vector<vector<int>> board;
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};

/**
 * @brief (0, 0)에서 (n-1, n-1)까지 [min_val, max_val] 범위의 값만 밟고
 * 도달할 수 있는지 확인하는 BFS 함수
 * @param min_val 경로에서 허용되는 최솟값
 * @param max_val 경로에서 허용되는 최댓값
 * @return 도달 가능하면 true, 불가능하면 false
 */
bool can_reach(int min_val, int max_val) {
    // 시작점과 끝점 자체가 범위를 벗어나면 즉시 실패
    if (board[0][0] < min_val || board[0][0] > max_val) return false;
    if (board[n-1][n-1] < min_val || board[n-1][n-1] > max_val) return false;

    queue<pair<int, int>> q;
    vector<vector<bool>> visited(n, vector<bool>(n, false));

    q.push({0, 0});
    visited[0][0] = true;

    while (!q.empty()) {
        pair<int, int> cur = q.front();
        q.pop();

        int r = cur.first;
        int c = cur.second;

        // 도착
        if (r == n - 1 && c == n - 1) {
            return true;
        }

        for (int dir = 0; dir < 4; ++dir) {
            int nr = r + dx[dir];
            int nc = c + dy[dir];

            // 1. 맵 범위 체크
            if (nr < 0 || nr >= n || nc < 0 || nc >= n) continue;
            // 2. 방문 여부 체크
            if (visited[nr][nc]) continue;

            // 3. 값 범위 체크 (핵심)
            if (board[nr][nc] >= min_val && board[nr][nc] <= max_val) {
                visited[nr][nc] = true;
                q.push({nr, nc});
            }
        }
    }

    // 큐가 비었는데 도착 못함
    return false;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);

    cin >> n;
    board.resize(n, vector<int>(n));
    set<int> s;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> board[i][j];
            s.insert(board[i][j]);
        }
    }

    // 중복 제거된 값들을 정렬된 벡터로 옮김
    vector<int> unique_vals(s.begin(), s.end());
    int k = unique_vals.size();
    
    int min_overall_diff = 2e9;
    int max_idx = 0; // 투 포인터의 'end' 포인터

    // 'start' 포인터를 0부터 k-1까지 순회
    for (int min_idx = 0; min_idx < k; ++min_idx) {
        
        // can_reach가 true가 될 때까지 max_idx를 증가시킴
        while (max_idx < k && !can_reach(unique_vals[min_idx], unique_vals[max_idx])) {
            max_idx++;
        }

        // max_idx가 끝까지 도달했다면,
        // 현재 min_idx (및 이후의 모든 min_idx)에 대해
        // 가능한 경로가 더 이상 없다는 의미
        if (max_idx == k) {
            break; 
        }

        // 경로를 찾음: [min_idx, max_idx]
        min_overall_diff = min(min_overall_diff, unique_vals[max_idx] - unique_vals[min_idx]);
    }
    
    cout << min_overall_diff << '\n';

    return 0;
}