#include <iostream>
#include <vector>
#include <unordered_set>
#include <string>
using namespace std;

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    int n;
    cin >> n;

    vector<unordered_set<string>> students(101);

    for (int i = 0; i < n; i++)
    {
        string name;
        cin >> name;

        for (int j = 0; j < name.size(); j++)
        {
            string substring = name.substr(j);
            students[substring.size()].insert(substring);
        }
    }

    for (int i = 0; i < 101; i++)
    {
        if (students[i].size() == n)
        {
            cout << i << '\n';
            break;
        }
    }

    return 0;
}