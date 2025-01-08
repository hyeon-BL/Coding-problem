#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    int o, w; // 적정 체중, 실제 체중
    string scenario;
    vector<string> scenarios;
    int n;
    int cnt = 1;
    bool flag = false;
    while (true)
    {
        cin >> o >> w;
        if (o == 0 && w == 0)
        {
            for (int i = 0; i < scenarios.size(); i++)
            {
                cout << scenarios[i] << "\n";
            }
            return 0;
        }
        while (true)
        {
            cin >> scenario;
            cin >> n;
            if (scenario == "E")
            {
                w -= n;
                if (w <= 0 && !flag)
                {
                    scenarios.push_back(to_string(cnt) + " " + "RIP");
                    cnt++;
                    flag = true;
                }
            }
            else if (scenario == "F")
            {
                w += n;
            }
            else if (scenario == "#")
            {
                if (w > o / 2 && w < o * 2 && !flag)
                {
                    scenarios.push_back(to_string(cnt) + " " + ":-)");
                }
                else if (flag)
                {
                    scenarios.push_back(to_string(cnt) + " " + "RIP");
                }
                else if (!flag)
                {
                    scenarios.push_back(to_string(cnt) + " " + ":-(");
                }
                cnt++;
                break;
            }
        }
    }
}