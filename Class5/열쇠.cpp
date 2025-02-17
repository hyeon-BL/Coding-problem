#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
#include <algorithm>
using namespace std;

int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};

int bfs(vector<vector<char>> &arr, vector<char> &keys, int H, int W)
{
    vector<vector<bool>> visited(H, vector<bool>(W, false));
    unordered_map<char, vector<pair<int, int>>> doors;
    queue<pair<int, int>> q;
    int max_value = 0;

    // 경계에서 들어갈 수 있는 곳을 큐에 추가
    for (int i = 0; i < H; i++)
    {
        for (int j = 0; j < W; j++)
        {
            if (i == 0 || i == H - 1 || j == 0 || j == W - 1)
            {
                if (arr[i][j] != '*' && !visited[i][j])
                {
                    if (arr[i][j] >= 'A' && arr[i][j] <= 'Z')
                    {                               // 문이 있는 경우
                        char door = arr[i][j] + 32; // 대문자를 소문자로 변경
                        if (find(keys.begin(), keys.end(), door) != keys.end())
                        { // 열쇠가 있는 경우
                            q.push({i, j});
                            visited[i][j] = true;
                        }
                        else
                        { // 열쇠가 없는 경우
                            doors[door].push_back({i, j});
                        }
                    }
                    else
                    { // 문이 아닌 경우
                        q.push({i, j});
                        visited[i][j] = true;
                    }
                }
            }
        }
    }

    while (!q.empty())
    {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        if (arr[x][y] == '$')
        { // 문서를 찾은 경우
            max_value++;
        }
        else if (arr[x][y] >= 'a' && arr[x][y] <= 'z')
        { // 열쇠를 찾은 경우
            keys.push_back(arr[x][y]);
            if (doors.find(arr[x][y]) != doors.end())
            { // 해당 열쇠로 열 수 있는 문이 있는 경우
                for (auto door : doors[arr[x][y]])
                {
                    q.push(door);
                    visited[door.first][door.second] = true;
                }
                doors.erase(arr[x][y]);
            }
        }

        for (int i = 0; i < 4; i++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (nx >= 0 && nx < H && ny >= 0 && ny < W && !visited[nx][ny] && arr[nx][ny] != '*')
            {
                if (arr[nx][ny] >= 'A' && arr[nx][ny] <= 'Z')
                {                                 // 문이 있는 경우
                    char door = arr[nx][ny] + 32; // 대문자를 소문자로 변경
                    if (find(keys.begin(), keys.end(), door) != keys.end())
                    { // 열쇠가 있는 경우
                        q.push({nx, ny});
                        visited[nx][ny] = true;
                    }
                    else
                    { // 열쇠가 없는 경우
                        doors[door].push_back({nx, ny});
                    }
                }
                else
                { // 문이 없는 경우
                    q.push({nx, ny});
                    visited[nx][ny] = true;
                }
            }
        }
    }

    return max_value;
}

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    int T;
    cin >> T;
    while (T--)
    {
        int H, W;
        cin >> H >> W;
        vector<vector<char>> arr(H, vector<char>(W));
        vector<char> keys;
        for (int i = 0; i < H; i++)
        {
            string s;
            cin >> s;
            for (int j = 0; j < W; j++)
            {
                arr[i][j] = s[j];
            }
        }
        string key;
        cin >> key;
        if (key != "0")
        {
            for (int i = 0; i < key.size(); i++)
            {
                keys.push_back(key[i]);
            }
        }

        int max_value = bfs(arr, keys, H, W);
        cout << max_value << '\n';
    }
}

/*
방문처리: 문을 발견한 경우 -> 열쇠가 있는지 확인 / 열쇠를 발견한 경우 -> 열쇠를 추가하고 열 수 있는 문이 있는지 확인
1
5 17
*****************
.............**$*
*B*A*P*C**X*Y*.X.
*y*x*a*p**$*$**$*
*****************



예외처리: 문이 경계에 있는 경우
1
7 7
*ABCDE*
X.....F
W.$$$.G
V.$$$.H
U.$$$.J
T.....K
*SQPML*
irony
*/