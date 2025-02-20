#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool isPrefix(const string &prefix, const string &word)
{ // prefix가 word의 접두사인지 확인
    return word.substr(0, prefix.size()) == prefix;
}

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    int N;
    cin >> N;
    vector<string> words(N);

    for (int i = 0; i < N; i++)
    {
        cin >> words[i];
    }

    // 단어들을 길이 순으로 정렬
    sort(words.begin(), words.end(), [](const string &a, const string &b)
         { return a.size() > b.size(); });

    int maxSubsetSize = 0;
    vector<string> prefixFreeSet;

    for (const string &word : words)
    {
        bool isPrefixOfAny = false;
        for (const string &prefix : prefixFreeSet)
        { // prefix가 어떤 단어의 접두사인지 확인
            if (isPrefix(word, prefix))
            { // 접두사인 경우
                isPrefixOfAny = true;
                break;
            }
        }
        if (!isPrefixOfAny)
        { // 접두사가 아닌 경우
            prefixFreeSet.push_back(word);
            maxSubsetSize++;
        }
    }

    cout << maxSubsetSize;
    return 0;
}