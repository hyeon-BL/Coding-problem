#include <iostream>
#include <vector>
using namespace std;

bool is_prime[4000001];
vector<int> primes; // 소수 저장

void sieve(int max_num)
{
    fill(is_prime, is_prime + max_num + 1, true);
    is_prime[0] = is_prime[1] = false;
    for (int i = 2; i * i <= max_num; i++)
    { // 2부터 sqrt(max_num)까지 검사
        if (is_prime[i])
        {
            for (int j = i * i; j <= max_num; j += i)
            { // i의 배수들을 소수에서 제외
                is_prime[j] = false;
            }
        }
    }
    for (int i = 2; i <= max_num; i++)
    {
        if (is_prime[i])
        {
            primes.push_back(i);
        }
    }
}

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    int N;
    cin >> N;

    sieve(4000000);

    int start = 0, end = 0, sum = 0, count = 0; // 투 포인터
    while (start <= end && end <= primes.size())
    { // 투포인터 접근에서 start <= end는 필수
        if (sum < N)
        { // start부터 end까지의 합이 N보다 작으면 end를 증가시킴
            sum += primes[end++];
        }
        else if (sum > N)
        { // start부터 end까지의 합이 N보다 크면 start를 증가시킴
            sum -= primes[start++];
        }
        else
        { // sum == N
            count++;
            sum += primes[end++];
        }
    }

    cout << count;
    return 0;
}