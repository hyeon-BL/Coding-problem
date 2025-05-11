#include <iostream>
#include <vector>
#include <string>
using namespace std;

// 팰린드롬: 앞에서 읽으나 뒤에서 읽으나 같은 문자열
// 부분 문자열 중 팰린드롬의 개수를 구하는 문제
/*
문자열 최대 200만 자 -> 메모리 초과 발생 가능
팰린드롬의 길이를 구하는 Manacher 알고리즘을 사용하여 O(n)으로 해결
'연속하는' 부분 문자열을 팰린드롬 길이 / 2로 구할 수 있음
*/

int main()
{
    string s;
    cin >> s; // 입력 문자열

    // 문자열 전처리: 홀수 길이와 짝수 길이 팰린드롬을 통일적으로 처리하기 위해 '#' 삽입
    string t = "#";
    for (char c : s)
    {
        t += c;
        t += "#";
    }

    int n = t.size();
    vector<int> res(n, 0); // 각 위치에서 팰린드롬의 반지름 저장
    int p = 0, r = 0;      // 현재 가장 오른쪽까지 확장된 팰린드롬의 중심(p)과 오른쪽 끝(r)
    long long total = 0;   // 팰린드롬 부분 문자열의 총 개수

    for (int i = 0; i < n; i++)
    {
        // i가 r 안에 있다면 대칭성을 이용해 초기 반지름 설정
        if (i <= r)
        {
            res[i] = min(r - i, res[2 * p - i]);
        }

        // 팰린드롬 확장
        while (i - res[i] - 1 >= 0 && i + res[i] + 1 < n && t[i - res[i] - 1] == t[i + res[i] + 1])
        {
            res[i]++;
        }

        // r 갱신
        if (i + res[i] > r)
        {
            p = i;
            r = i + res[i];
        }

        // 팰린드롬 개수 누적 (res[i]는 팰린드롬 반지름이므로 길이는 res[i])
        total += res[i] / 2; // 실제 문자열 기준으로 팰린드롬 개수 추가
    }

    total += s.size(); // 각 문자 자체도 팰린드롬이므로 추가
    cout << total;     // 팰린드롬 부분 문자열의 총 개수 출력
    return 0;
}