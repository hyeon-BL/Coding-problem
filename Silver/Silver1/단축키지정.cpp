#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <set>

#define INF 987654321
using namespace std;

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    int N; // 옵션 개수
    cin >> N;
    cin.ignore(); // newline character 제거

    vector<vector<string>> options(N);
    set<char> usedKeys; // 사용된 단축키

    // 옵션 입력
    for (int i = 0; i < N; i++)
    {
        string option;
        getline(cin, option);
        istringstream iss(option);
        string word;
        while (iss >> word)
        {
            options[i].push_back(word);
        }
    }

    vector<char> assignedKeys(N, ' ');
    vector<pair<int, int>> index(N, {INF, INF});

    // 단축키 할당
    for (int i = 0; i < N; i++)
    {
        bool keyAssigned = false;

        // 첫번째 character로 단축키 할당
        for (int j = 0; j < options[i].size(); j++)
        {
            char key = tolower(options[i][j][0]);
            if (usedKeys.find(key) == usedKeys.end())
            { // 사용되지 않은 단축키인 경우
                usedKeys.insert(key);
                assignedKeys[i] = key;
                keyAssigned = true;
                index[i] = {j, 0};
                break;
            }
        }

        // 할당된 단축키가 없는 경우
        if (!keyAssigned)
        {
            for (int j = 0; j < options[i].size(); j++)
            {
                for (char c : options[i][j])
                {
                    char key = tolower(c);
                    if (usedKeys.find(key) == usedKeys.end())
                    { // 사용되지 않은 단축키인 경우
                        usedKeys.insert(key);
                        assignedKeys[i] = key;
                        keyAssigned = true;
                        index[i] = {j, options[i][j].find(c)};
                        break;
                    }
                }
                if (keyAssigned)
                    break;
            }
        }
    }

    // 출력
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < options[i].size(); j++)
        {
            for (int k = 0; k < options[i][j].size(); k++)
            {
                if (j == index[i].first && k == index[i].second)
                {
                    cout << "[" << options[i][j][k] << "]";
                }
                else
                {
                    cout << options[i][j][k];
                }
            }
            cout << " ";
        }
        cout << "\n";
    }

    return 0;
}