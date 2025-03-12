#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

vector<int> arr;

/*
    세그먼트 트리: 최솟값의 인덱스 구하기(logN) 자료구조
    특정 구간을 빠르게 탐색하기 위한 자료구조
    세그먼트 트리는 구간을 나누어 저장하고, 각 노드에는 그 구간의 최솟값의 인덱스를 저장한다.
*/

struct SegmentTree
{
    vector<int> minIndexTree;
    int size;

    SegmentTree()
    {
        size = arr.size();
        minIndexTree.resize(4 * size);
        build(0, 0, size - 1);
    }

    void build(int node, int start, int end)
    {
        if (start == end)
        {
            minIndexTree[node] = start;
        }
        else
        {
            int mid = (start + end) / 2;
            build(2 * node + 1, start, mid);
            build(2 * node + 2, mid + 1, end);
            int leftIndex = minIndexTree[2 * node + 1];
            int rightIndex = minIndexTree[2 * node + 2];
            minIndexTree[node] = (arr[leftIndex] <= arr[rightIndex]) ? leftIndex : rightIndex;
        }
    }

    void update(int node, int start, int end, int index, int value)
    { // 값 변경
        if (start == end)
        {
            arr[index] = value;
            minIndexTree[node] = index;
        }
        else
        {
            int mid = (start + end) / 2;
            if (index <= mid)
            {
                update(2 * node + 1, start, mid, index, value);
            }
            else
            {
                update(2 * node + 2, mid + 1, end, index, value);
            }
            int leftIndex = minIndexTree[2 * node + 1];
            int rightIndex = minIndexTree[2 * node + 2];
            minIndexTree[node] = (arr[leftIndex] <= arr[rightIndex]) ? leftIndex : rightIndex;
        }
    }

    int query(int node, int start, int end, int l, int r)
    {
        if (r < start || end < l)
        {
            return -1;
        }
        if (l <= start && end <= r)
        {
            return minIndexTree[node];
        }
        int mid = (start + end) / 2;
        int leftIndex = query(2 * node + 1, start, mid, l, r);
        int rightIndex = query(2 * node + 2, mid + 1, end, l, r);
        if (leftIndex == -1)
            return rightIndex;
        if (rightIndex == -1)
            return leftIndex;
        return (arr[leftIndex] <= arr[rightIndex]) ? leftIndex : rightIndex;
    }

    int query(int l, int r)
    { // 구간 쿼리
        return query(0, 0, size - 1, l, r);
    }
};

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    int N; // 수열의 크기
    cin >> N;

    arr.resize(N);
    for (int i = 0; i < N; ++i)
    {
        cin >> arr[i];
    }

    SegmentTree segTree;

    int M; // 쿼리의 개수
    cin >> M;

    while (M--)
    {
        int query_type;
        cin >> query_type;

        if (query_type == 1)
        {
            int index, value;
            cin >> index >> value;
            segTree.update(0, 0, N - 1, index - 1, value);
        }
        else
        {
            int left, right;
            cin >> left >> right;
            int result = segTree.query(left - 1, right - 1);
            cout << result + 1 << '\n';
        }
    }

    return 0;
}