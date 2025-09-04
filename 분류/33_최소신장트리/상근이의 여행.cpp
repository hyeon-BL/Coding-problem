#include <iostream>
#include <vector>
using namespace std;

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    int T;
    cin >> T;
    while (T--)
    {
        int N, M;
        cin >> N >> M;
        vector<vector<int>> graph(N + 1);
        vector<bool> visited(N + 1, false);
        for (int i = 0; i < M; i++)
        {
            int u, v;
            cin >> u >> v;
            graph[u].push_back(v);
            graph[v].push_back(u);
        }

        int result = INT_MAX;
        for (int i = 1; i <= N; i++)
        {
            int path_count = 0;
            vector<int> stack = {i};
            visited[i] = true;
            while (!stack.empty())
            {
                int node = stack.back();
                stack.pop_back();
                for (int neighbor : graph[node])
                {
                    if (!visited[neighbor])
                    {
                        visited[neighbor] = true;
                        stack.push_back(neighbor);
                        path_count++;
                    }
                }
            }
            result = min(result, path_count);
            visited.assign(N + 1, false);
        }
        cout << result << "\n";
    }
}

/*
#include<iostream>
int main() {
    int T;
    std::cin >> T;
    while (T--) {
        int N, M;
        std::cin >> N >> M;
        while (M--) {
          int u, v;
          std::cin >> u >> v;
        }
        std::cout << N - 1 << '\n';
    }
}

알고보니 그래프가 연결 그래프라서 DFS로 탐색할 필요가 없었다.
=> 모든 정점을 방문하는 최소 간선의 개수는 정점의 개수 - 1 이다.

*/