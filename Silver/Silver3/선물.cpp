#include <iostream>
#include <iomanip>
using namespace std;

bool canFit(long long N, long long L, long long W, long long H, double A)
{
    long long countL = L / A;
    long long countW = W / A;
    long long countH = H / A;
    return (countL * countW * countH) >= N; // N개 이상의 정육면체를 만들 수 있는지 확인
}

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    long long N, L, W, H;
    cin >> N >> L >> W >> H;

    double left = 0, right = min(min(L, W), H);
    double mid;

    for (int i = 0; i < 100; ++i)
    { // 10^-9까지 정확도를 가지기 위해 100번 반복
        mid = (left + right) / 2;
        if (canFit(N, L, W, H, mid))
        {
            left = mid;
        }
        else
        {
            right = mid;
        }
    }

    cout << fixed << setprecision(10) << left;

    return 0;
}