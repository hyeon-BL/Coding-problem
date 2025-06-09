#include <iostream>
#include <map>
using namespace std;

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    int n; // 출입 기록 수
    cin >> n;

    map<string, bool> records; // 출입 기록을 저장할 맵
    for (int i = 0; i < n; ++i)
    {
        string name, action;
        cin >> name >> action; // 이름과 출입 기록(enter/leave) 입력
        // 출입 기록이 "enter"인 경우
        if (action == "enter")
        {
            // 이름이 맵에 없으면 출입 기록 추가
            if (records.find(name) == records.end())
            {
                records[name] = true; // 출입 기록 추가
            }
        }
        // 출입 기록이 "leave"인 경우
        else if (action == "leave")
        {
            // 이름이 맵에 있으면 출입 기록 제거
            if (records.find(name) != records.end())
            {
                records.erase(name); // 출입 기록 제거
            }
        }
    }

    // 출입 기록이 남아있는 사람들을 출력(내림차순)
    for (auto it = records.rbegin(); it != records.rend(); ++it)
    {
        cout << it->first << '\n'; // 이름 출력
    }
}