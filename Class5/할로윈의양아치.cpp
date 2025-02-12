#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class UnionFind
{
private:
    vector<int> parent, rank;

public:
    UnionFind(int n) : parent(n), rank(n, 0)
    {
        for (int i = 0; i < n; i++)
            parent[i] = i;
    }

    int find(int x)
    {
        if (parent[x] != x)
            parent[x] = find(parent[x]);
        return parent[x];
    }

    void unite(int x, int y)
    {
        x = find(x), y = find(y);
        if (x == y)
            return;
        if (rank[x] < rank[y])
            swap(x, y);
        parent[y] = x;
        if (rank[x] == rank[y])
            rank[x]++;
    }
};

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    int N, M, K;
    cin >> N >> M >> K; // N: 아이 수, M: 친구 관계 수, K: 최대 아이 수

    vector<int> candies(N + 1);
    for (int i = 1; i <= N; i++)
    {
        cin >> candies[i];
    }

    // Union-Find 초기화
    UnionFind uf(N + 1);
    for (int i = 0; i < M; i++)
    {
        int a, b;
        cin >> a >> b;
        uf.unite(a, b);
    }

    // connected components로 그룹화
    vector<vector<int>> groups(N + 1); // 각 그룹에 속한 아이들의 사탕 수
    for (int i = 1; i <= N; i++)
    {
        groups[uf.find(i)].push_back(candies[i]);
    }

    vector<pair<int, int>> sumCandies; // 그룹별 사탕 수 합과 그룹 크기
    for (int i = 1; i <= N; i++)
    {
        if (groups[i].empty())
            continue;
        int sum = 0;
        for (int candy : groups[i])
        {
            sum += candy;
        }
        sumCandies.push_back({sum, groups[i].size()});
    }

    // Knapsack 알고리즘
    int maxCandies = 0;
    vector<int> dp(K + 1, 0); // dp[j]: j 크기의 가방에 들어갈 수 있는 최대 사탕 수
    for (int i = 0; i < sumCandies.size(); i++)
    { // i번째 그룹의 사탕 수 합과 그룹 크기
        int sum = sumCandies[i].first;
        int size = sumCandies[i].second;
        for (int j = K - 1; j >= size; j--)
        { // j: 현재 가방의 크기
            dp[j] = max(dp[j], dp[j - size] + sum);
            maxCandies = max(maxCandies, dp[j]);
        }
    }

    cout << maxCandies;
    return 0;
}