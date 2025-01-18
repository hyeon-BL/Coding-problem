#include <iostream>
#include <vector>
#include <queue> // Include queue for topological sort
using namespace std;

struct Node
{
    int time;
    int indegree; // 들어가는 간선의 개수
    vector<int> next;
};

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    int T;
    int N, K;

    cin >> T;
    while (T--)
    {
        cin >> N >> K;
        vector<Node> nodes(N + 1);
        vector<int> dp(N + 1, 0);

        for (int i = 1; i <= N; i++)
        {
            cin >> nodes[i].time;
        }

        for (int i = 0; i < K; i++)
        {
            int X, Y;
            cin >> X >> Y;
            nodes[X].next.push_back(Y);
            nodes[Y].indegree++;
        }

        int W;
        cin >> W;

        queue<int> q;
        for (int i = 1; i <= N; i++)
        {
            if (nodes[i].indegree == 0)
            { // 시작점
                dp[i] = nodes[i].time;
                q.push(i);
            }
        }

        while (!q.empty())
        { // topological sort - 시작점에서 출발하여 indegree를 줄여가며 탐색
            int curr = q.front();
            q.pop();

            for (int next : nodes[curr].next)
            { // 다음 노드들 중에서 max값을 찾아 dp에 저장('동시'에 가능하므로 max만 찾으면 됨)
                dp[next] = max(dp[next], dp[curr] + nodes[next].time);
                if (--nodes[next].indegree == 0)
                { // 다음 노드로 들어가는 간선이 없는 경우
                    q.push(next);
                }
            }
        }

        cout << dp[W] << '\n';
    }
}