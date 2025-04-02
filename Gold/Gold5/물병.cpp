#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int countSetBits(int n)
{ // n의 이진수 표현에서 1의 개수를 세는 함수
    int count = 0;
    while (n > 0)
    {
        count += (n & 1);
        n >>= 1;
    }
    return count;
}

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    int N, K; // N: 물병의 개수, K: 옮길 수 있는 물병의 개수
    cin >> N >> K;

    int additionalBottles = 0;
    while (countSetBits(N) > K)
    {
        N++;
        additionalBottles++;
    }

    cout << additionalBottles;
    return 0;
}