#include <iostream>
#include <vector>
#include <string>
using namespace std;

vector<vector<int>> image;
string quadtree;

void compress(int x, int y, int size)
{
    if (size == 1)
    {
        quadtree += to_string(image[x][y]);
        return;
    }

    bool isUniform = true;
    int firstValue = image[x][y];

    for (int i = x; i < x + size; i++)
    {
        for (int j = y; j < y + size; j++)
        {
            if (image[i][j] != firstValue)
            {
                isUniform = false;
                break;
            }
        }
        if (!isUniform)
            break;
    }

    if (isUniform)
    { // 모든 값이 동일한 경우
        quadtree += to_string(firstValue);
    }
    else
    { // 다른 값이 있는 경우 -> 쪼개기
        quadtree += '(';
        int halfSize = size / 2;
        compress(x, y, halfSize);
        compress(x, y + halfSize, halfSize);
        compress(x + halfSize, y, halfSize);
        compress(x + halfSize, y + halfSize, halfSize);
        quadtree += ')';
    }
}

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    int N;
    cin >> N;

    image.resize(N, vector<int>(N));
    for (int i = 0; i < N; i++)
    {
        string row;
        cin >> row;
        for (int j = 0; j < N; j++)
        {
            image[i][j] = row[j] - '0';
        }
    }

    quadtree.clear();
    compress(0, 0, N);
    cout << quadtree << '\n';
}