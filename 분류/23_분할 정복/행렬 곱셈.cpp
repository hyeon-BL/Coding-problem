#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> operator*(const vector<vector<int>> &A, const vector<vector<int>> &B)
{
    int N = A.size(), M = A[0].size(), K = B[0].size();
    vector<vector<int>> C(N, vector<int>(K, 0));
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < K; j++)
        {
            for (int k = 0; k < M; k++)
            {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }
    return C;
}

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    int N, M;
    cin >> N >> M;
    vector<vector<int>> A(N, vector<int>(M));
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            cin >> A[i][j];
        }
    }

    int M2, K;
    cin >> M2 >> K;
    vector<vector<int>> B(M, vector<int>(K));
    for (int i = 0; i < M; i++)
    {
        for (int j = 0; j < K; j++)
        {
            cin >> B[i][j];
        }
    }

    vector<vector<int>> C = A * B;
    for (const auto &row : C)
    {
        for (const auto &val : row)
        {
            cout << val << ' ';
        }
        cout << '\n';
    }
}