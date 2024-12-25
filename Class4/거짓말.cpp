#include <iostream>
#include <vector>
using namespace std;

vector<int> parent;

/*
union-find 알고리즘
1. 초기화: 각 원소의 부모를 자기 자신으로 초기화
2. find: 루트 노드를 찾는 함수
3. unite: 두 집합을 하나로 합치는 함수

진실을 아는 사람들의 그룹을 찾아 unite
*/

int find(int x)
{
    if (parent[x] == x)
        return x;
    return parent[x] = find(parent[x]);
}

void unite(int x, int y)
{
    x = find(x);
    y = find(y);
    if (x != y)
        parent[y] = x;
}

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    int N, M, tp; // N: 사람 수, M: 파티 수, tp: 진실을 아는 사람 수
    cin >> N >> M;

    parent.resize(N + 1);
    for (int i = 1; i <= N; ++i)
    {
        parent[i] = i;
    }

    vector<int> truth;
    vector<vector<int>> party(M);

    cin >> tp;
    for (int i = 0; i < tp; i++)
    {
        int t;
        cin >> t;
        truth.push_back(t);
    }

    for (int i = 0; i < M; ++i)
    {
        int num;
        cin >> num;
        int first_person;
        cin >> first_person;
        party[i].push_back(first_person);
        for (int j = 1; j < num; ++j)
        {
            int p;
            cin >> p;
            party[i].push_back(p);
            unite(first_person, p);
        }
    }

    vector<bool> isTruth(N + 1, false);
    for (int i = 0; i < truth.size(); i++)
    {
        isTruth[find(truth[i])] = true; // 진실을 아는 사람의 그룹
    }

    int cnt = 0;
    for (int i = 0; i < M; ++i)
    {
        bool isTrue = false;
        for (int j = 0; j < party[i].size(); ++j)
        {
            if (isTruth[find(party[i][j])])
            {
                isTrue = true;
                break;
            }
        }
        if (!isTrue)
        {
            cnt++;
        }
    }

    cout << cnt;
    return 0;
}