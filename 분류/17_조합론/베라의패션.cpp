#include <iostream>
using namespace std;

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    int N;
    cin >> N;

    cout << N * N - N << '\n'; // 조합: N * N, '서로다른': - N => N * (N - 1) = nP2
    return 0;
}