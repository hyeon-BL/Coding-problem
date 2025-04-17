#include <stdio.h>

int diff(int N, int N_two)
{
    int result = 0;
    for (int i = 0; i < 32; i++)
    {
        int bit1 = (N >> i) & 1;     // N의 i번째 비트
        int bit2 = (N_two >> i) & 1; // N의 2의 보수의 i번째 비트
        result += (bit1 ^ bit2);     // XOR 연산을 통해 서로 다른 비트 수를 계산
    }
    return result; // 서로 다른 비트 수 반환
}

int main()
{
    int N;
    scanf("%d", &N);

    int N_two = ~N + 1;          // N의 2의 보수
    int result = diff(N, N_two); // 서로 다른 비트 수 계산
    printf("%d\n", result);      // 결과 출력
}