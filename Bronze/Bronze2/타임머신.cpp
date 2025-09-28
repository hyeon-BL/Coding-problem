#include <iostream>
#include <string>
#include <vector>
using namespace std;

void backtrack(vector<string> &parts, vector<bool> &used, vector<string> &current, int &count)
{
    if (current.size() == 3)
    {
        int hh = stoi(current[0]);
        int mm = stoi(current[1]);
        int ss = stoi(current[2]);
        if (hh >= 1 && hh <= 12 && mm >= 0 && mm <= 59 && ss >= 0 && ss <= 59)
            count++;
        return;
    }

    for (int i = 0; i < parts.size(); i++)
    {
        if (!used[i])
        {
            used[i] = true;
            current.push_back(parts[i]);
            backtrack(parts, used, current, count);
            current.pop_back();
            used[i] = false;
        }
    }
}

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    string time;
    cin >> time;

    vector<string> parts;
    size_t pos = 0;
    while ((pos = time.find(':')) != string::npos)
    {
        parts.push_back(time.substr(0, pos));
        time.erase(0, pos + 1);
    }
    parts.push_back(time);

    int count = 0;
    vector<bool> used(parts.size(), false);
    vector<string> current;
    backtrack(parts, used, current, count);

    cout << count;
}