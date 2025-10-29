#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int g_count = 0;

bool is_lucky(const string &s)
{
    char prev_char = '\0';
    for (char ch : s)
    {
        if (ch == prev_char)
            return false;
        prev_char = ch;
    }
    return true;
}

void find_combination(string &cur, const string &s, vector<bool> &used, int target_length)
{
    if ((int)cur.length() == target_length)
    {
        if (is_lucky(cur))
            ++g_count;
        return;
    }

    for (int i = 0; i < (int)s.size(); ++i)
    {
        if (used[i])
            continue;
        if (i > 0 && s[i] == s[i - 1] && !used[i - 1])
            continue; // 인접한 문자가 같지 않도록

        used[i] = true;
        cur.push_back(s[i]);
        find_combination(cur, s, used, target_length);
        cur.pop_back();
        used[i] = false;
    }
}

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    string s;
    cin >> s;
    sort(s.begin(), s.end()); // 중복 처리용 정렬
    vector<bool> used(s.length(), false);
    string cur;
    find_combination(cur, s, used, s.length());
    cout << g_count << '\n';
}