#include <iostream>
using namespace std;

/*
MenOfPassion(A[], n) {
    sum <- 0;
    for i <- 1 to n - 1
        for j <- i + 1 to n
            sum <- sum + A[i] × A[j]; # 코드1 -> n-1, n-2, ..., 1번 실행됨(2중 for문)
    return sum;
}
*/

long long sum(long long n)
{
    long long result = (n * (n - 1)) / 2; // 1부터 n-1까지의 합
    return result;
}

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    long long n; // 입력의 크기
    cin >> n;

    cout << sum(n) << '\n'
         << 2; // O(n^2) -> 2
}