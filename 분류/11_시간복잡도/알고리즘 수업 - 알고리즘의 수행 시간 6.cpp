#include <iostream>
using namespace std;

/*
MenOfPassion(A[], n) {
    sum <- 0;
    for i <- 1 to n - 2
        for j <- i + 1 to n - 1
            for k <- j + 1 to n
                sum <- sum + A[i] × A[j] × A[k]; # 코드1
    return sum;
}

n = 7
i = 1 2 3 4 5
j = 2 3 4 5 6
k = 3 4 5 6 7

시간복잡도: O(n^3)
수행횟수:
5 + 4 + 3 + 2 + 1 = 15
4 + 3 + 2 + 1 = 10
3 + 2 + 1 = 6
2 + 1 = 3
1 = 1
수행횟수 = 15 + 10 + 6 + 3 + 1 = 35
*/

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    long long n; // 입력의 크기
    cin >> n;

    cout << (n * (n - 1) * (n - 2)) / 6 << '\n' // nC3 = n! / (3! * (n - 3)!) = n * (n - 1) * (n - 2) / 6
         << 3;
}