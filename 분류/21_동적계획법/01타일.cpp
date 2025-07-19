#include <iostream>
#include <vector>
using namespace std;

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    int n;
    cin >> n;
    vector<int> tiles(n + 1);
    tiles[1] = 1;
    tiles[2] = 2;
    for (int i = 3; i <= n; i++)
        tiles[i] = (tiles[i - 1] + tiles[i - 2]) % 15746;

    cout << tiles[n] << '\n';
    return 0;
}

/*
n-2에 00을 붙이거나
n-1에 1을 붙이는 경우


tiles[1] = 1
tiles[2] = 2
tiles[3] = 3
tiles[4] = 5
tiles[5] = 8
*/