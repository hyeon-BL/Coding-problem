#include <iostream>
#include <vector>
using namespace std;

struct operation
{
    int A, B, C; // A: 작업의 종류, B: 사탕의 순위, C: 사탕의 개수
};

class FenwickTree
{ // Binary Indexed Tree
    vector<int> tree;

public:
    FenwickTree(int size) : tree(size + 1, 0) {}

    void update(int index, int delta)
    { // O(logN)
        // index: 수정할 위치, delta: 수정할 값
        while (index < tree.size())
        {
            tree[index] += delta;
            index += index & -index;
        }
    }

    int query(int index)
    { // O(logN)
        // index: 구간의 끝 위치
        int sum = 0;
        while (index > 0)
        {
            sum += tree[index];
            index -= index & -index;
        }
        return sum;
    }

    int findKth(int k)
    { // O(logN)
        // k: 찾고자 하는 순위
        int index = 0, sum = 0;
        for (int i = 20; i >= 0; i--)
        { // Adjust based on max size (2^20 > 1,000,000)
            int nextIndex = index + (1 << i);
            if (nextIndex < tree.size() && sum + tree[nextIndex] < k)
            {
                sum += tree[nextIndex];
                index = nextIndex;
            }
        }
        return index + 1;
    }
};

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    int n;
    cin >> n; // 작업의 수
    vector<operation> operations(n + 1);

    for (int i = 1; i <= n; i++)
    {
        int a, b;
        cin >> a >> b;
        if (a == 2)
        { // a == 2 (사탕을 넣는 경우)
            int c;
            cin >> c;
            operations[i] = {a, b, c};
        }
        else
        { // a == 1 (사탕을 꺼내는 경우)
            operations[i] = {a, b, 0};
        }
    }

    FenwickTree fenwick(1'000'000); // Initialize Fenwick Tree
    vector<int> result;             // 결과

    for (int i = 1; i <= n; i++)
    {
        if (operations[i].A == 1)
        { // 사탕을 꺼내는 경우
            int rank = fenwick.findKth(operations[i].B);
            result.push_back(rank);
            fenwick.update(rank, -1);
        }
        else
        { // 사탕을 넣는 경우
            fenwick.update(operations[i].B, operations[i].C);
        }
    }

    for (int res : result)
    {
        cout << res << '\n';
    }
}