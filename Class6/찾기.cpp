#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    string T, P;
    getline(cin, T);
    getline(cin, P);

    // LPS 배열 만들기
    // P의 접두사와 접미사가 같은 최대 길이를 저장하는 배열을 만든다.
    auto buildLPS = [](const string &P)
    {
        vector<int> lps(P.size(), 0);
        int j = 0;
        for (int i = 1; i < P.size(); i++)
        {
            while (j > 0 && P[i] != P[j])
            {
                j = lps[j - 1];
            }
            if (P[i] == P[j])
            {
                j++;
                lps[i] = j;
            }
        }
        return lps;
    };

    // KMP 알고리즘
    // T에서 P가 나타나는 모든 시작 위치를 찾는다.
    auto KMP = [](const string &T, const string &P, const vector<int> &lps)
    {
        vector<int> result;
        int j = 0;
        for (int i = 0; i < T.size(); i++)
        {
            while (j > 0 && T[i] != P[j])
            {
                j = lps[j - 1];
            }
            if (T[i] == P[j])
            {
                j++;
                if (j == P.size())
                {
                    result.push_back(i - j + 1); // P가 나타나는 시작 위치
                    j = lps[j - 1];
                }
            }
        }
        return result;
    };

    vector<int> lps = buildLPS(P);

    vector<int> matches = KMP(T, P, lps);

    cout << matches.size() << '\n'; // P가 나타나는 횟수

    for (int index : matches)
    {                             // P가 나타나는 모든 시작 위치 출력
        cout << index + 1 << ' '; // 1-based index
    }

    return 0;
}