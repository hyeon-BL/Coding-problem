#include <iostream>
#include <vector>
using namespace std;

struct Node
{
    int data;
    Node *next;
};

vector<bool> visited(100001, false);
vector<bool> finished(100001, false);
vector<Node> tree(100001);
int cnt = 0;

void hasCycle(int node)
{
    visited[node] = true;
    int next = tree[node].data;

    if (!visited[next])
    { // 처음 방문한 경우(DFS)
        hasCycle(next);
    }
    else if (!finished[next])
    { // 사이클이 발생한 경우(방문 했지만 아직 끝나지 않은 경우)
        for (int i = next; i != node; i = tree[i].data)
        { // 사이클을 이루는 노드들을 찾는다
            cnt++;
        }
        cnt++; // 자기 자신을 더해준다
    }
    finished[node] = true;
}

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    int T, n;
    cin >> T;
    while (T--)
    {
        cin >> n;
        for (int i = 1; i <= n; i++)
        { // 1 ~ n
            int data;
            cin >> data;
            tree[i].data = data;
            tree[i].next = &tree[data];
        }

        cnt = 0;
        for (int i = 1; i <= n; i++)
        {
            if (!visited[i])
            { // 방문하지 않은 노드에 대해서만 사이클을 찾는다
                hasCycle(i);
            }
        }
        cout << n - cnt << '\n';

        fill(visited.begin(), visited.end(), false);
        fill(finished.begin(), finished.end(), false);
        tree.clear();
    }
}