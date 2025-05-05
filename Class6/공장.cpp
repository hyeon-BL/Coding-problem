#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

// Fenwick Tree로 crossing count
class FenwickTree
{
    vector<int> tree;

public:
    FenwickTree(int n) : tree(n + 1, 0) {}

    void update(int idx, int delta)
    { // delta를 idx에 더함
        while (idx < tree.size())
        {
            tree[idx] += delta;
            idx += idx & -idx;
        }
    }

    int query(int idx)
    { // idx까지의 합을 구함
        int sum = 0;
        while (idx > 0)
        {
            sum += tree[idx];
            idx -= idx & -idx;
        }
        return sum;
    }
};

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    int N; // 기계의 개수
    cin >> N;

    vector<int> row_A(N); // A열
    vector<int> row_B(N); // B열

    for (int i = 0; i < N; ++i)
        cin >> row_A[i];
    for (int i = 0; i < N; ++i)
        cin >> row_B[i];

    // Step 1: B열의 기계 번호를 인덱스로 매핑
    unordered_map<int, int> B_index;
    for (int i = 0; i < N; ++i)
    {
        B_index[row_B[i]] = i + 1;
    }

    // Step 2: Fenwick Tree를 사용하여 crossing count 계산
    FenwickTree fenwick(N);
    long long count = 0;

    for (int element_A : row_A)
    {
        int index_B = B_index[element_A]; // B열에서 A열의 기계 찾기

        // index_B+1 ~ N 사이 기계 중 방문한 기계의 개수 카운트
        count += fenwick.query(N) - fenwick.query(index_B);

        // index_B를 방문 처리 -> 구간합만큼 crossing이 일어남
        fenwick.update(index_B, 1);
    }

    cout << count;
    return 0;
}

// O(n^2) 풀이
// int main()
// {
//     cin.tie(0);
//     ios::sync_with_stdio(0);

//     int N; // 기계의 개수
//     cin >> N;
//     vector<int> row_A(N);           // A열의 기계들
//     vector<int> row_B(N);           // B열의 기계들
//     vector<bool> visited(N, false); // 방문 여부
//     for (int i = 0; i < N; ++i)
//         cin >> row_A[i];
//     for (int i = 0; i < N; ++i)
//         cin >> row_B[i];

//     int count = 0; // 겹치는 경우
//     for (int element_A : row_A)
//     {
//         int index_B = find(row_B.begin(), row_B.end(), element_A) - row_B.begin(); // B열에서 A열의 기계 찾기
//         if (index_B < N)
//         {
//             visited[index_B] = true; // B열에서 A열의 기계가 있는 경우 방문 처리
//         }

//         for (int i = index_B + 1; i < N; ++i)
//         {
//             if (visited[i])
//             {
//                 count++; // 겹치는 경우 카운트
//             }
//         }
//     }
//     cout << count;
// }