#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

vector<int> arr;

/*
    세그먼트 트리: 최솟값과 최댓값 구하기(logN) 자료구조
    특정 구간을 빠르게 탐색하기 위한 자료구조
    세그먼트 트리는 구간을 나누어 저장하고, 각 노드에는 그 구간의 최솟값과 최댓값을 저장한다.
*/

struct SegmentTree
{
    vector<int> minTree, maxTree;
    int size;

    SegmentTree()
    {
        size = arr.size();
        minTree.resize(4 * size);
        maxTree.resize(4 * size);
        build(0, 0, size - 1);
    }

    void build(int node, int start, int end)
    {
        if (start == end)
        {
            minTree[node] = arr[start];
            maxTree[node] = arr[start];
        }
        else
        {
            int mid = (start + end) / 2;
            build(2 * node + 1, start, mid);
            build(2 * node + 2, mid + 1, end);
            minTree[node] = min(minTree[2 * node + 1], minTree[2 * node + 2]);
            maxTree[node] = max(maxTree[2 * node + 1], maxTree[2 * node + 2]);
        }
    }

    pair<int, int> query(int node, int start, int end, int l, int r)
    {
        if (r < start || end < l)
        {
            return {INT_MAX, INT_MIN};
        }
        if (l <= start && end <= r)
        {
            return {minTree[node], maxTree[node]};
        }
        int mid = (start + end) / 2;
        auto left = query(2 * node + 1, start, mid, l, r);
        auto right = query(2 * node + 2, mid + 1, end, l, r);
        return {min(left.first, right.first), max(left.second, right.second)};
    }

    pair<int, int> query(int l, int r)
    { // 구간 쿼리
        return query(0, 0, size - 1, l, r);
    }
};

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    int N, M; // N: 수의 개수, M: a/b 쌍
    cin >> N >> M;

    arr.resize(N);
    for (int i = 0; i < N; ++i)
    {
        cin >> arr[i];
    }

    SegmentTree segTree;

    vector<int> a(M), b(M);
    for (int i = 0; i < M; ++i)
    {
        cin >> a[i] >> b[i];
    }

    for (int i = 0; i < M; ++i)
    {
        int a_value = a[i] - 1, b_value = b[i] - 1;
        auto result = segTree.query(a_value, b_value); // a부터 b까지의 최솟값과 최댓값
        cout << result.first << ' ' << result.second << '\n';
    }

    return 0;
}