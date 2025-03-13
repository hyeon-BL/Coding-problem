#include <iostream>
#include <vector>
using namespace std;

vector<int> digitCount(10, 0);

void countDigits(int N)
{
    int factor = 1;
    while (factor <= N)
    {
        int lowerNumbers = N - (N / factor) * factor; // 현재 자릿수보다 낮은 자릿수
        int currentDigit = (N / factor) % 10;         // 현재 자릿수
        int higherNumbers = N / (factor * 10);        // 현재 자릿수보다 높은 자릿수

        // higherNumbers를 count
        for (int i = 0; i < 10; ++i)
        {
            digitCount[i] += higherNumbers * factor;
        }

        // currentDigit을 count
        for (int i = 0; i < currentDigit; ++i)
        {
            digitCount[i] += factor;
        }
        digitCount[currentDigit] += lowerNumbers + 1;

        // 0이 맨 앞에 나오는 경우 예외처리
        digitCount[0] -= factor;

        factor *= 10;
    }
}

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);
    int N; // 전체 페이지 수
    cin >> N;

    countDigits(N);

    for (int i = 0; i < 10; ++i)
    {
        cout << digitCount[i] << ' ';
    }

    return 0;
}