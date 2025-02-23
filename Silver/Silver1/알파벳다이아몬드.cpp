#include <iostream>
using namespace std;

char get_char(int N, int i, int j)
{
    if (j >= N - i - 1 && j <= N + i - 1 && i <= N - 1)
    {
        if (j >= N - 1)
        { // 우측 위
            return 'a' + (j - i) % 26;
        }
        else
        { // 좌측 위
            return 'a' + (N - 1 - i + (N - j) - 1) % 26;
        }
    }
    else if (j >= i - N + 1 && j <= 3 * N - 3 - i && i >= N)
    {
        if (j >= N - 1)
        { // 우측 아래
            return 'a' + (j + i - 2 * N + 2) % 26;
        }
        else
        { // 좌측 아래
            return 'a' + (i - j) % 26;
        }
    }
    return '.';
}

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    int N, R1, C1, R2, C2;
    cin >> N >> R1 >> C1 >> R2 >> C2;

    for (int i = R1; i <= R2; i++)
    {
        for (int j = C1; j <= C2; j++)
        {
            cout << get_char(N, i % (2 * N - 1), j % (2 * N - 1));
        }
        cout << '\n';
    }

    return 0;
}

/*
test case
3 0 0 4 4
answer
..c..
.cbc.
cbabc
.cbc.
..c..

5 0 0 8 8
....e....
...ede...
..edcde..
.edcbcde.
edcbabcde
.edcbcde.
..edcde..
...ede...
....e....

*/

/*
메모리 초과 : 전체 alphabet_diamond를 저장 후 출력

#include <iostream>
#include <vector>
using namespace std;

vector<vector<char>> make_alphabet_diamond(int N)
{
    vector<vector<char>> diamond(2 * N - 1, vector<char>(2 * N - 1, '.'));
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N + i; j++)
        {
            if (j >= N - i - 1)
            {
                if (j >= N - 1)
                {
                    diamond[i][j] = diamond[i][2 * N - 2 - j] = 'a' + j - i;
                    diamond[2 * N - 2 - i][j] = diamond[2 * N - 2 - i][2 * N - 2 - j] = 'a' + j - i;
                }
            }
        }
    }

    return diamond;
}

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    int N, R1, C1, R2, C2;
    cin >> N >> R1 >> C1 >> R2 >> C2;

    vector<vector<char>> diamond = make_alphabet_diamond(N);

    for (int i = R1; i <= R2; i++)
    {
        for (int j = C1; j <= C2; j++)
        {
            cout << diamond[i % (2 * N - 1)][j % (2 * N - 1)];
        }
        cout << '\n';
    }
}

*/