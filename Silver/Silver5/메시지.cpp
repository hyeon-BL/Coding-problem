#include <iostream>
#include <vector>
using namespace std;

struct student
{
    string name;
};

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    int N, cnt = 1;

    while (true)
    {
        cin >> N;
        if (N == 0)
        {
            break;
        }
        vector<student> students(N);
        vector<pair<int, int>> messages;
        cin.ignore();
        for (int i = 0; i < N; i++)
        {
            cin >> students[i].name;
            for (int j = 1; j < N; j++)
            {
                char PorN;
                cin >> PorN;
                if (PorN == 'N')
                {
                    messages.push_back({(i - j + N) % N, i});
                }
            }
        }

        cout << "Group " << cnt << '\n';
        if (messages.empty())
        {
            cout << "Nobody was nasty\n";
        }
        else
        {
            for (auto message : messages)
            {
                cout << students[message.first].name << " was nasty about " << students[message.second].name << '\n';
            }
        }
        cout << '\n';
        cnt++;
    }
}