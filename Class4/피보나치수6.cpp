#include <iostream>
using namespace std;

/*
fibonacci number using matrix exponentiation
- 피보나치 수열을 행렬 거듭제곱을 이용해 구하는 문제
- 시간 복잡도: O(logN)


*/

const int MOD = 1'000'000'007;

struct Matrix
{
    long long mat[2][2];
};

Matrix multiply(Matrix a, Matrix b)
{
    Matrix result;
    result.mat[0][0] = (a.mat[0][0] * b.mat[0][0] + a.mat[0][1] * b.mat[1][0]) % MOD; // 1행 1열
    result.mat[0][1] = (a.mat[0][0] * b.mat[0][1] + a.mat[0][1] * b.mat[1][1]) % MOD; // 1행 2열
    result.mat[1][0] = (a.mat[1][0] * b.mat[0][0] + a.mat[1][1] * b.mat[1][0]) % MOD; // 2행 1열
    result.mat[1][1] = (a.mat[1][0] * b.mat[0][1] + a.mat[1][1] * b.mat[1][1]) % MOD; // 2행 2열
    return result;
}

Matrix matrix_pow(Matrix base, long long exp)
{
    Matrix result = {{{1, 0}, {0, 1}}}; // 단위 행렬(초기값)
    while (exp > 0)
    {
        if (exp % 2 == 1)
        {                                    // 홀수면
            result = multiply(result, base); // result * base
        }
        base = multiply(base, base); // base^2
        exp /= 2;
    }
    return result;
}

long long fibonacci(long long N)
{
    if (N == 0)
        return 0;
    if (N == 1)
        return 1;

    Matrix base = {{{1, 1}, {1, 0}}};
    Matrix result = matrix_pow(base, N - 1);
    return result.mat[0][0];
}

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    long long N;
    cin >> N;

    cout << fibonacci(N) % MOD;

    return 0;
}