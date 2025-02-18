#include <iostream>
#include <vector>
using namespace std;

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    int N; // 적은 내용의 길이
    cin >> N;
    string s;
    cin >> s;

    // # = 벽, . = 길
    vector<vector<char>> maze(2 * N + 1, vector<char>(2 * N + 1, '#'));
    int x = N, y = N; // 중심에서 시작
    maze[x][y] = '.'; // '.' = 현재 위치

    // Directions: 0 = 북, 1 = 동, 2 = 남, 3 = 서
    int dir = 2;
    int dx[] = {-1, 0, 1, 0};
    int dy[] = {0, 1, 0, -1};

    for (char c : s)
    {
        if (c == 'R')
        {
            dir = (dir + 1) % 4;
        }
        else if (c == 'L')
        {
            dir = (dir + 3) % 4;
        }
        else if (c == 'F')
        {
            x += dx[dir];
            y += dy[dir];
            maze[x][y] = '.';
        }
    }

    // x, y의 최소, 최대값 찾기 -> 시작과 끝점 찾기
    int minX = 2 * N, minY = 2 * N, maxX = 0, maxY = 0;
    for (int i = 0; i < 2 * N + 1; i++)
    {
        for (int j = 0; j < 2 * N + 1; j++)
        {
            if (maze[i][j] == '.')
            {
                minX = min(minX, i);
                minY = min(minY, j);
                maxX = max(maxX, i);
                maxY = max(maxY, j);
            }
        }
    }

    // 출력
    for (int i = minX; i <= maxX; i++)
    {
        for (int j = minY; j <= maxY; j++)
        {
            cout << maze[i][j];
        }
        cout << '\n';
    }

    return 0;
}