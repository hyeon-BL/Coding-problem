#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map> // hash map for counting words
using namespace std;

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    int N, M;
    cin >> N >> M;

    unordered_map<string, int> wordCount;
    string word;

    for (int i = 0; i < N; i++)
    {
        cin >> word;
        if (word.length() >= M)
        {
            wordCount[word]++;
        }
    }

    vector<pair<string, int>> words;
    for (const auto &pair : wordCount)
    {
        words.push_back({pair.first, pair.second});
    }

    sort(words.begin(), words.end(), [](const pair<string, int> &a, const pair<string, int> &b)
         {
        if (a.second != b.second)
        {
            return a.second > b.second; // 빈도수가 높은 순서
        }
        else if (a.first.length() != b.first.length())
        {
            return a.first.length() > b.first.length(); // 길이가 긴 순서
        }
        else
        {
            return a.first < b.first; // 사전 순서
        } });

    for (const auto &w : words)
    {
        cout << w.first << '\n';
    }

    return 0;
}