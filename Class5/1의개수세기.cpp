#include <iostream>
#include <vector>
using namespace std;

vector<long long> pow_2;

long long countOnes(long long n)
{
    long long cnt = n & 1; // n이 홀수인 경우 1의 개수는 1개

    for (int i = 54; i > 0; i--)
    {
        if (n & (1LL << i))
        { // n의 i번째 비트가 1이라면
            cnt += pow_2[i - 1];
            n -= (1LL << i); // n의 i번째 비트를 0으로 만들어줌
            cnt += n + 1;
        }
    }
    return cnt;
}

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    long long start, end;
    cin >> start >> end;

    long long cnt = 0;
    pow_2.push_back(1);

    // 2의 제곱수들을 저장
    for (int i = 1; i <= 54; i++)
    { // pow_2[i] = 2^i + 2^(i - 1) + ... + 2^0
        pow_2.push_back(pow_2[i - 1] * 2 + (1LL << i));
    }

    // 세부적인 count
    cnt = countOnes(end) - countOnes(start - 1);
    cout << cnt;
}

/*
2 : 10 -> 1개
1
3 : 11 -> 2개
4 : 100 -> 1개
4
5 : 101 -> 2개
6 : 110 -> 2개
7 : 111 -> 3개
8 : 1000 -> 1개
12
9 : 1001 -> 2개
10 : 1010 -> 2개
11 : 1011 -> 3개
12 : 1100 -> 2개
13 : 1101 -> 3개
14 : 1110 -> 3개
15 : 1111 -> 4개
16 : 10000 -> 1개
32
*/