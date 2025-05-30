#include <iostream>
using namespace std;

/*
MenOfPassion(A[], n) {
    sum <- 0;
    for i <- 1 to n
        for j <- 1 to n
            sum <- sum + A[i] × A[j]; # 코드1 -> n^2번 실행됨(2중 for문)
    return sum;
}
}
*/

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    long long n; // 입력의 크기
    cin >> n;

    cout << n * n << '\n'
         << 2;
}