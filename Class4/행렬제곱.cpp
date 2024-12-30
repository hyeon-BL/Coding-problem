#include <iostream>
#include <vector>
using namespace std;

vector<vector<long long>> matrixMultiply(vector<vector<long long>> &a, vector<vector<long long>> &b)
{ // a와 b는 N*N 행렬 (N <= 5)
    int N = a.size();
    vector<vector<long long>> result(N, vector<long long>(N));
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            for (int k = 0; k < N; k++)
            {
                result[i][j] += a[i][k] * b[k][j];
            }
            result[i][j] %= 1000;
        }
    }
    return result;
}

vector<vector<long long>> matrixPow(vector<vector<long long>> &a, long long b)
{ // a는 N*N 행렬 (N <= 5)
    int N = a.size();
    vector<vector<long long>> result(N, vector<long long>(N));
    for (int i = 0; i < N; i++)
    {
        result[i][i] = 1; // 단위 행렬로 초기화 (A^0 = I)
    }
    while (b > 0)
    {
        if (b % 2 == 1)
        {
            result = matrixMultiply(result, a);
        }
        a = matrixMultiply(a, a);
        b /= 2;
    }
    return result;
}

// 행렬 제곱을 이용한 행렬 거듭제곱
/*
example)
A^8 = A^4 * A^4 = A^2 * A^2 * A^2 * A^2 = A * A * A * A * A * A * A * A
*/

int main()
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    int N;
    long long B;
    cin >> N >> B;
    vector<vector<long long>> matrix(N, vector<long long>(N));
    vector<vector<long long>> result(N, vector<long long>(N));
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cin >> matrix[i][j];
        }
    }

    result = matrixPow(matrix, B);
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cout << result[i][j] << ' ';
        }
        cout << '\n';
    }
}