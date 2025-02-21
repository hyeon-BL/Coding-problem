#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Shark
{
    int r, c, s, d, z;
    bool alive;
};

vector<Shark> sharks;
vector<vector<int>> map;
int R, C, M;

int dr[] = {-1, 1, 0, 0}; // 상, 하, 우, 좌
int dc[] = {0, 0, 1, -1};

void move_sharks()
{
    vector<vector<int>> new_map(R, vector<int>(C, -1));
    for (int i = 0; i < M; i++)
    {
        if (!sharks[i].alive)
            continue;
        int r = sharks[i].r;
        int c = sharks[i].c;
        int s = sharks[i].s;
        int d = sharks[i].d;

        if (d == 0 || d == 1)
            s %= (2 * (R - 1)); // 상, 하 -> 2 * (R - 1) 만큼 이동하면 제자리
        else
            s %= (2 * (C - 1)); // 우, 좌 -> 2 * (C - 1) 만큼 이동하면 제자리

        for (int j = 0; j < s; j++)
        { // 속력만큼 이동
            if (r + dr[d] < 0 || r + dr[d] >= R || c + dc[d] < 0 || c + dc[d] >= C)
            {
                d = (d % 2 == 0) ? d + 1 : d - 1; // 방향 반대로
            }
            r += dr[d];
            c += dc[d];
        }

        sharks[i].r = r;
        sharks[i].c = c;
        sharks[i].d = d;

        if (new_map[r][c] == -1 || sharks[new_map[r][c]].z < sharks[i].z)
        { // 상어가 없거나, 기존 상어보다 크기가 큰 경우
            if (new_map[r][c] != -1)
            { // 기존 상어가 있으면 죽음
                sharks[new_map[r][c]].alive = false;
            }
            new_map[r][c] = i; // 상어 이동
        }
        else
        { // 기존 상어가 더 큰 경우
            sharks[i].alive = false;
        }
    }
    map = new_map;
}

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    cin >> R >> C >> M;
    map.resize(R, vector<int>(C, -1));
    sharks.resize(M);

    for (int i = 0; i < M; i++)
    {
        cin >> sharks[i].r >> sharks[i].c >> sharks[i].s >> sharks[i].d >> sharks[i].z;
        sharks[i].r--;
        sharks[i].c--; // 0-based index
        sharks[i].d--; // 0-based direction
        sharks[i].alive = true;
        map[sharks[i].r][sharks[i].c] = i;
    }

    int ans = 0;

    for (int fisher = 0; fisher < C; fisher++)
    { // 1. 낚시왕 이동
        for (int row = 0; row < R; row++)
        { // 2. 가까운 상어 잡기
            if (map[row][fisher] != -1)
            {
                ans += sharks[map[row][fisher]].z;
                sharks[map[row][fisher]].alive = false;
                map[row][fisher] = -1;
                break;
            }
        }
        move_sharks(); // 3. 상어 이동
    }

    cout << ans;
    return 0;
}