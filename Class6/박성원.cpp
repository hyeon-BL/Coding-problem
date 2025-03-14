#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int N, K;
vector<string> numbers;
vector<int> remainders; // 각 숫자의 나머지 값
vector<int> tenPowers;  // 10의 거듭제곱의 나머지 값
vector<vector<long long>> dp;

long long gcd(long long a, long long b)
{
    return b ? gcd(b, a % b) : a;
}

// 숫자 문자열의 나머지 계산
int calculateRemainder(const string &num)
{
    int result = 0;
    for (char digit : num)
    {
        result = (result * 10 + (digit - '0')) % K;
    }
    return result;
}

// dynamic programming
// used: 사용한 숫자의 비트마스크, currentMod: 현재 나머지 값
long long solve(int used, int currentMod)
{
    // 모든 숫자를 사용한 경우
    if (used == (1 << N) - 1)
    {
        return currentMod == 0 ? 1 : 0;
    }

    // 이미 계산된 경우
    if (dp[used][currentMod] != -1)
    {
        return dp[used][currentMod];
    }

    dp[used][currentMod] = 0;
    long long result = 0;
    for (int i = 0; i < N; i++)
    {
        if (!(used & (1 << i)))
        { // i번째 숫자를 아직 사용하지 않은 경우
            int nextMod = ((currentMod * tenPowers[numbers[i].length()]) % K + remainders[i]) % K;
            dp[used][currentMod] += solve(used | (1 << i), nextMod);
        }
    }

    return dp[used][currentMod]; // 메모이제이션
}

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    cin >> N;
    numbers.resize(N);
    for (int i = 0; i < N; i++)
    {
        cin >> numbers[i];
    }
    cin >> K;

    // 10의 거듭제곱의 나머지 값 계산
    tenPowers.resize(51); // 최대 50자리
    tenPowers[0] = 1 % K;
    for (int i = 1; i <= 50; i++)
    {
        tenPowers[i] = (tenPowers[i - 1] * 10) % K;
    }

    // 각 숫자의 나머지 값 계산
    remainders.resize(N);
    for (int i = 0; i < N; i++)
    {
        remainders[i] = calculateRemainder(numbers[i]);
    }

    // dp 배열 초기화
    dp.assign(1 << N, vector<long long>(K, -1));

    // 전체 경우의 수 계산 (N!)
    long long total = 1;
    for (int i = 1; i <= N; i++)
    {
        total *= i;
    }

    // K로 나누어 떨어지는 경우의 수 계산
    long long count = solve(0, 0);

    // 최대공약수로 나누어 기약분수 만들기
    long long g = gcd(count, total);
    cout << count / g << '/' << total / g;

    return 0;
}

/*
시간초과 -> O(N!)의 시간복잡도를 가지는 코드
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

long long gcd(long long a, long long b)
{
    return b ? gcd(b, a % b) : a;
}

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    int N, K;
    cin >> N; // N개의 수

    vector<string> A(N);
    for (int i = 0; i < N; ++i)
    {
        cin >> A[i];
    }

    cin >> K; // modulo K == 0

    long long count = 0;
    long long total = 0;

    // 각 숫자 문자열의 모듈러 값을 미리 계산하여 저장
    // vector<int> mod_values(N);
    // for (int i = 0; i < N; ++i)
    // {
    //     long long mod_value = 0;
    //     for (char digit : A[i])
    //     {
    //         mod_value = (mod_value * 10 + (digit - '0')) % K;
    //     }
    //     mod_values[i] = mod_value;
    // }

    sort(A.begin(), A.end());
    do
    {
        long long combined_mod = 0;
        for (int i = 0; i < N; ++i)
        {
            for (char digit : A[i])
            {
                combined_mod = (combined_mod * 10 + (digit - '0')) % K;
            }
        }
        if (combined_mod == 0)
        {
            count++;
        }
        total++;
    } while (next_permutation(A.begin(), A.end()));

    // 최대 공약수로 나누기
    long long divide = gcd(count, total);
    count /= divide;
    total /= divide;

    cout << count << '/' << total;

    return 0;
}

*/