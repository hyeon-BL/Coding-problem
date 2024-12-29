#include <iostream>
using namespace std;
int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    int N, M, distance = 0;
    cin >> N >> M;

    int N_i, N_j, M_i, M_j;
    N_i = N % 4 == 0 ? N / 4 : N / 4 + 1;
    N_j = N % 4 == 0 ? 4 : N % 4;
    M_i = M % 4 == 0 ? M / 4 : M / 4 + 1;
    M_j = M % 4 == 0 ? 4 : M % 4;

    distance = abs(N_i - M_i) + abs(N_j - M_j);
    cout << distance;
}