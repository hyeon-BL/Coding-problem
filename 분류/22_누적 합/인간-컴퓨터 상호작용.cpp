#include <iostream>
#include <vector>
using namespace std;

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    string s;
    cin >> s;

    vector<vector<int>> count(26, vector<int>(s.size(), 0));
    for (int i = 0; i < s.size(); i++)
    {
        for (int j = 0; j < 26; j++)
        {
            count[j][i] = count[j][i > 0 ? i - 1 : 0];
        }
        count[s[i] - 'a'][i]++;
    }

    int q;
    cin >> q;
    while (q--)
    {
        char c;
        cin >> c;
        int idx = c - 'a';

        int l, r;
        cin >> l >> r;

        int result = (l == 0 ? count[idx][r] : count[idx][r] - count[idx][l - 1]);
        cout << result << "\n";
    }
    return 0;
}