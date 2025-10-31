#include <iostream>
using namespace std;

double combination(double n, double r)
{
    double result = 1;
    for (int i = 0; i < r; ++i)
        result = result * (n - i) / (i + 1);
    return result;
}

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    double N, M, K;
    cin >> N >> M >> K;

    // Total cases: N choose M
    double total_cases = combination(N, M);

    // Favorable cases: (N - K) choose (M - K) ~ (N - K) choose M
    double favorable_cases = 0;
    for (int i = K; i <= M; ++i)
        favorable_cases += combination(M, i) * combination(N - M, M - i);

    cout.precision(10);
    cout << fixed << favorable_cases / total_cases << '\n';
}