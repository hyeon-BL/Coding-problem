#include <iostream>
#include <queue>
using namespace std;

// bfs solution -> slower than dynamic programming solution
struct State
{
    int x, y, dir;
};

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    int arr[16][16] = {
        0,
    };
    int N;
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
            cin >> arr[i][j];
    }
    if (arr[N - 1][N - 1] == 1)
    {
        cout << 0;
        return 0;
    }

    int cnt = 0;
    queue<State> q;
    q.push({0, 1, 0}); // 시작 상태 (0,1)에서 가로 방향(0)

    while (!q.empty())
    {
        State curr = q.front();
        q.pop();

        int x = curr.x;
        int y = curr.y;
        int dir = curr.dir;

        if (x == N - 1 && y == N - 1)
        {
            cnt++;
            continue;
        }

        // 가로 방향
        if (dir == 0 || dir == 2)
        {
            if (y + 1 < N && arr[x][y + 1] == 0)
            {
                q.push({x, y + 1, 0});
            }
        }

        // 세로 방향
        if (dir == 1 || dir == 2)
        {
            if (x + 1 < N && arr[x + 1][y] == 0)
            {
                q.push({x + 1, y, 1});
            }
        }

        // 대각선 방향
        if (x + 1 < N && y + 1 < N && arr[x + 1][y] == 0 && arr[x][y + 1] == 0 && arr[x + 1][y + 1] == 0)
        {
            q.push({x + 1, y + 1, 2});
        }
    }

    cout << cnt;

    return 0;
}

// dynamic programming solution -> O(n^2)
/*
#include <iostream>
using namespace std;

int arr[16][16];
int dp[16][16][3];

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);

    int N;
    cin >> N;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> arr[i][j];
        }
    }

    // Initialize the starting position
    dp[0][1][0] = 1;

    for (int x = 0; x < N; x++) {
        for (int y = 0; y < N; y++) {
            if (arr[x][y] == 1) continue; // Skip blocked cells

            // Horizontal to Horizontal
            if (y + 1 < N && arr[x][y + 1] == 0) {
                dp[x][y + 1][0] += dp[x][y][0];
            }
            // Horizontal to Diagonal
            if (x + 1 < N && y + 1 < N && arr[x + 1][y] == 0 && arr[x][y + 1] == 0 && arr[x + 1][y + 1] == 0) {
                dp[x + 1][y + 1][2] += dp[x][y][0];
            }

            // Vertical to Vertical
            if (x + 1 < N && arr[x + 1][y] == 0) {
                dp[x + 1][y][1] += dp[x][y][1];
            }
            // Vertical to Diagonal
            if (x + 1 < N && y + 1 < N && arr[x + 1][y] == 0 && arr[x][y + 1] == 0 && arr[x + 1][y + 1] == 0) {
                dp[x + 1][y + 1][2] += dp[x][y][1];
            }

            // Diagonal to Horizontal
            if (y + 1 < N && arr[x][y + 1] == 0) {
                dp[x][y + 1][0] += dp[x][y][2];
            }
            // Diagonal to Vertical
            if (x + 1 < N && arr[x + 1][y] == 0) {
                dp[x + 1][y][1] += dp[x][y][2];
            }
            // Diagonal to Diagonal
            if (x + 1 < N && y + 1 < N && arr[x + 1][y] == 0 && arr[x][y + 1] == 0 && arr[x + 1][y + 1] == 0) {
                dp[x + 1][y + 1][2] += dp[x][y][2];
            }
        }
    }

    // Sum up the ways to reach the bottom-right corner in any direction
    int result = dp[N - 1][N - 1][0] + dp[N - 1][N - 1][1] + dp[N - 1][N - 1][2];
    cout << result;

    return 0;
}


*/