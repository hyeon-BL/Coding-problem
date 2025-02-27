#include <iostream>
#include <vector>
using namespace std;

const int MOD = 1'000'000'007;
const int N = 8;

vector<vector<long long>> multiply(const vector<vector<long long>> &a, const vector<vector<long long>> &b)
{ // 행렬 A * 행렬 B
    vector<vector<long long>> result(N, vector<long long>(N, 0));
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            for (int k = 0; k < N; k++)
            { // 행렬 곱셈
                result[i][j] = (result[i][j] + a[i][k] * b[k][j]) % MOD;
            }
        }
    }
    return result;
}

vector<vector<long long>> matrix_exponentiation(vector<vector<long long>> base, int exp)
{ // 행렬 거듭제곱
    vector<vector<long long>> result(N, vector<long long>(N, 0));
    for (int i = 0; i < N; i++)
    { // 단위 행렬
        result[i][i] = 1;
    }
    while (exp > 0)
    { // 분할 정복을 이용한 행렬 거듭제곱
        if (exp % 2 == 1)
        { // 홀수인 경우
            result = multiply(result, base);
        }
        base = multiply(base, base);
        exp /= 2;
    }
    return result;
}

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    int D; // D분 후
    cin >> D;

    vector<vector<long long>> adj = {
        {0, 1, 0, 1, 0, 1, 0, 0},
        {1, 0, 1, 0, 0, 0, 0, 0},
        {0, 1, 0, 1, 0, 0, 0, 0},
        {1, 0, 1, 0, 1, 1, 0, 0},
        {0, 0, 0, 1, 0, 1, 1, 1},
        {1, 0, 0, 1, 1, 0, 1, 0},
        {0, 0, 0, 0, 1, 1, 0, 1},
        {0, 0, 0, 0, 1, 0, 1, 0}};

    vector<vector<long long>> result = matrix_exponentiation(adj, D); // D분 후의 인접 행렬
    // result[i][j] = i번 건물에서 j번 건물로 이동하는 경우의 수

    cout << result[7][7]; // "정보과학관" index = 7
    return 0;
}