#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/*
union-find 알고리즘
1. 초기화
2. 게이트 번호를 받아서 도킹 가능한 게이트 중 가장 작은 번호의 게이트를 찾음(부모 노드 찾기)
3. 도킹 가능한 게이트 중 가장 작은 번호의 게이트로 도킹(부모 노드 합치기)

입력
4
3
4
1
1

게이트
0 1 2 3 4
0 1 2 3-4 -> parent[4] = 3
0-1 2 3-4 -> parent[1] = 0
0-1 2 3-4 -> docking = 0 (불가능)
*/

int find(vector<int> &parent, int x)
{ // 부모 노드 찾기
    if (parent[x] == x)
        return x;
    return parent[x] = find(parent, parent[x]);
}

void unionParent(vector<int> &parent, int a, int b)
{ // 부모 노드 합치기
    a = find(parent, a);
    b = find(parent, b);
    if (a < b)
        parent[b] = a;
    else
        parent[a] = b;
}

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    vector<int> gate_range;
    int G, P; // 게이트 수, 비행기 수
    cin >> G >> P;
    for (int i = 0; i < P; i++)
    {
        int g;
        cin >> g;
        gate_range.push_back(g);
    }

    int cnt = 0;
    vector<int> parent(G + 1);
    for (int i = 1; i <= G; i++)
    {
        parent[i] = i;
    }

    for (int i = 0; i < P; i++)
    { // 비행기 수만큼 반복
        int g = gate_range[i];
        int docking = find(parent, g); // 도킹 가능한 게이트 중 가장 작은 번호의 게이트
        if (docking == 0)
        { // 도킹 가능한 게이트가 없다면
            break;
        }
        else
        {
            cnt++;
            unionParent(parent, docking, docking - 1); // 도킹 가능한 게이트 중 가장 작은 번호의 게이트로 도킹
        }
    }

    cout << cnt;
}