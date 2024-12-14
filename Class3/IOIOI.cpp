#include<iostream>
#include <vector>
using namespace std;

vector<int> computeLPSArray(string pattern) { // LPS(Longest Proper Prefix which is also Suffix) 배열 계산
    int M = pattern.length();
    vector<int> lps(M);
    int len = 0;
    lps[0] = 0;

    int i = 1;
    while (i < M) { // i: pattern의 인덱스 (시간복잡도 O(M))
        if (pattern[i] == pattern[len]) {
            len++;
            lps[i] = len;
            i++;
        } else {
            if (len != 0) {
                len = lps[len - 1];
            } else {
                lps[i] = 0;
                i++;
            }
        }
    }
    return lps;
}

int KMPSearch(string pattern, string text) { // KMP 알고리즘(부분 문자열 검색)
    int M = pattern.length();
    int N = text.length();

    vector<int> lps = computeLPSArray(pattern);

    int i = 0;
    int j = 0;
    int count = 0;
    while (i < N) { // i: text의 인덱스, j: pattern의 인덱스 (시간복잡도 O(N))
        if (pattern[j] == text[i]) {
            j++;
            i++;
        }

        if (j == M) {
            count++;
            j = lps[j - 1];
        } else if (i < N && pattern[j] != text[i]) {
            if (j != 0) {
                j = lps[j - 1];
            } else {
                i++;
            }
        }
    }
    return count;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);

    int N, M;
    cin >> N >> M;
    string S;
    cin >> S;

    int cnt = 0;

    string PN = "IOI";
    for (int i = 0; i < N - 1; i++) {
        PN += "OI";
    }
    int result = KMPSearch(PN, S);
    cout << result;

    return 0;
}