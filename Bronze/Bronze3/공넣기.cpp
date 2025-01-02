#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int N, M;
    cin >> N >> M;

    vector<vector<int>> way(M, vector<int>(3));
    vector<int> bucket(N, 0);
    for (int i = 0; i < M; i++)
    {
        cin >> way[i][0] >> way[i][1] >> way[i][2];
    }

    for (int i = 0; i < M; i++)
    {
        for (int j = way[i][0] - 1; j < way[i][1]; j++)
        {
            bucket[j] = way[i][2];
        }
    }

    for (int i = 0; i < N; i++)
    {
        cout << bucket[i] << " ";
    }
}