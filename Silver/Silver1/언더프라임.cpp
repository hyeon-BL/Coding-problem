#include <iostream>
#include <vector>
using namespace std;

vector<int> sieve(int max_num)
{ // 에라토스테네스의 체
    vector<int> primes(max_num + 1, 1);
    primes[0] = primes[1] = 0;
    for (int i = 2; i * i <= max_num; i++)
    {
        if (primes[i])
        {
            for (int j = i * i; j <= max_num; j += i)
            {
                primes[j] = 0;
            }
        }
    }
    return primes; // 소수: 1, 합성수: 0인 vector 반환
}

int count_prime(int num, const vector<int> &primes)
{ // 소인수의 개수를 구하는 함수
    int count = 0;
    for (int i = 2; i <= num; i++)
    {
        while (num % i == 0 && primes[i])
        { // 소수인 경우 소인수의 개수를 구함
            count++;
            num /= i;
        }
    }
    return count;
}

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    int A, B;
    cin >> A >> B;

    int max_num = B;
    vector<int> primes = sieve(max_num);     // 소수(1), 합성수(0)를 구함
    vector<int> prime_count(max_num + 1, 0); // 소인수의 개수를 저장

    for (int i = 2; i <= max_num; i++)
    { // 소인수의 개수를 구함
        prime_count[i] = count_prime(i, primes);
    }

    int under_prime_count = 0;
    for (int i = A; i <= B; i++)
    {
        if (primes[prime_count[i]])
        { // i의 소인수의 개수가 소수인 경우
            under_prime_count++;
        }
    }

    cout << under_prime_count;
    return 0;
}