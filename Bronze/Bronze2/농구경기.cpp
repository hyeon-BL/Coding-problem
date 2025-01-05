#include <iostream>
#include <algorithm>
#include <set>
using namespace std;

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    int N;
    cin >> N;

    string *name = new string[N];
    string *sorted_name = new string[N];

    for (int i = 0; i < N; i++)
    {
        cin >> name[i];
        sorted_name[i] = name[i][0];
    }

    sort(sorted_name, sorted_name + N);

    set<string> s;
    for (int i = 0; i < N; i++)
    {
        s.insert(sorted_name[i]);
    }
    int *cnt = new int[s.size()]{0};

    for (auto &iter : s)
    {
        for (int i = 0; i < N; i++)
        {
            if (iter == sorted_name[i])
            {
                cnt[distance(s.begin(), s.find(iter))]++;
            }
        }
    }

    bool flag = false;
    for (int i = 0; i < s.size(); i++)
    {
        if (cnt[i] >= 5) // 5명 이상인 이름만 출력
        {
            auto it = s.begin();
            advance(it, i);
            cout << *it;
            flag = true;
        }
    }

    if (!flag)
    {
        cout << "PREDAJA";
    }
}
