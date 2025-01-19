#include<iostream>
#include<string>
using namespace std;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);

    int N;
    cin >> N;

    string* words = new string[N];

    for (int i = 0; i < N; ++i) {
        cin >> words[i];
    }
    auto isGroupWord = [](const string& word) {
        bool seen[26] = { false };
        char prev = '\0';
        for (char ch : word) {
            if (ch != prev) { // different from the previous character
                if (seen[ch - 'a']) return false;  // already seen
                seen[ch - 'a'] = true; // mark as seen
                prev = ch;
            }
        }
        return true;
    };

    int groupWordCount = 0;
    for (int i = 0; i < N; ++i) {
        if (isGroupWord(words[i])) {
            ++groupWordCount;
        }
    }

    cout << groupWordCount << '\n';
    delete[] words;
}