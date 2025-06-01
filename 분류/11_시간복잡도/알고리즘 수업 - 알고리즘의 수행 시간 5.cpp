#include <iostream>
using namespace std;

/*
MenOfPassion(A[], n) {
    sum <- 0;
    for i <- 1 to n
        for j <- 1 to n
            for k <- 1 to n
                sum <- sum + A[i] × A[j] × A[k]; # 코드1 -> n^3번 실행됨(3중 for문)
    return sum;
}
*/

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    long long n; // 입력의 크기
    cin >> n;

    cout << n * n * n << '\n' // pow는 double 타입을 반환하므로, n * n * n으로 계산 -> 소수점 오차 방지
         << 3;
}