#include <iostream>
#include <set>
#include <string>
using namespace std;

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    string S;
    set<string> st; // 부분 문자열을 저장할 집합
    cin >> S;       // 문자열 입력
    int N = S.size();

    for (int i = 0; i < N; ++i)
    {
        for (int j = i + 1; j <= N; ++j)
        {
            st.insert(S.substr(i, j - i)); // 부분 문자열 삽입
        }
    }
    cout << st.size() << '\n'; // 집합의 크기 출력
}