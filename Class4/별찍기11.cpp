#include <iostream>
#include <vector>
using namespace std;

void draw_star(vector<vector<char>> &map, int x, int y, int size)
{
    if (size == 3)
    {
        map[x][y + 2] = '*';
        map[x + 1][y + 1] = '*';
        map[x + 1][y + 3] = '*';
        map[x + 2][y] = '*';
        map[x + 2][y + 1] = '*';
        map[x + 2][y + 2] = '*';
        map[x + 2][y + 3] = '*';
        map[x + 2][y + 4] = '*';
        return;
    }

    int newSize = size / 2;
    draw_star(map, x, y + newSize, newSize);        // Top
    draw_star(map, x + newSize, y, newSize);        // Bottom left
    draw_star(map, x + newSize, y + size, newSize); // Bottom right
}

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    int N;
    cin >> N;

    int size = N;
    vector<vector<char>> map(size, vector<char>(2 * size - 1, ' '));

    draw_star(map, 0, 0, size);

    for (int i = 0; i < size; ++i)
    { // column : 0 ~ size-1
        for (int j = 0; j < 2 * size - 1; ++j)
        { // row : 0 ~ 2*size-2
            cout << map[i][j];
        }
        cout << '\n';
    }

    return 0;
}