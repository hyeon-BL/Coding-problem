#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    int N;
    cin >> N;
    vector<int> A(N);
    for (int i = 0; i < N; i++)
    {
        cin >> A[i];
    }

    vector<int> lis;                 // 증가하는 부분 수열
    vector<int> lis_indices;         // 증가하는 부분 수열의 인덱스
    vector<int> prev_indices(N, -1); // 이전 인덱스
    vector<int> pos(N, -1);          // 위치

    for (int i = 0; i < N; i++)
    { // LIS 구하기
        // lower_bound: 찾으려는 값 이상이 처음 나타나는 위치
        auto it = lower_bound(lis.begin(), lis.end(), A[i]);
        int idx = it - lis.begin(); // 삽입 위치

        if (it == lis.end())
        { // 증가하는 경우
            lis.push_back(A[i]);
            lis_indices.push_back(i);
        }
        else
        { // 갱신하는 경우
            *it = A[i];
            lis_indices[idx] = i;
        }

        if (idx > 0)
        { // 이전 값이 존재하는 경우
            prev_indices[i] = lis_indices[idx - 1];
        }
        pos[idx] = i; // 위치 갱신
    }

    int lis_length = lis.size();
    vector<int> result(lis_length);
    int k = pos[lis_length - 1]; // LIS의 마지막 값의 인덱스
    for (int i = lis_length - 1; i >= 0; i--)
    { // LIS 구하기
        result[i] = A[k];
        k = prev_indices[k];
    }

    cout << lis_length << "\n";
    for (int i = 0; i < lis_length; i++)
    {
        cout << result[i] << " ";
    }

    return 0;
}

/*
10 20 10 30 15 50
답: 4
10 20 30 50

0번째:
lis: [10]
lis_indices: [0]
prev_indices: [-1, -1, -1, -1, -1, -1]
pos: [0, -1, -1, -1, -1, -1]

1번째:
lis: [10, 20]
lis_indices: [0, 1]
prev_indices: [-1, 0, -1, -1, -1, -1]
pos: [0, 1, -1, -1, -1, -1]

2번째:
lis: [10, 20]
lis_indices: [2, 1]
prev_indices: [-1, 0, -1, -1, -1, -1]
pos: [2, 1, -1, -1, -1, -1]

3번째:
lis: [10, 20, 30]
lis_indices: [2, 1, 3]
prev_indices: [-1, 0, -1, 1, -1, -1]
pos: [2, 1, 3, -1, -1, -1]

4번째:
lis: [10, 15, 30]
lis_indices: [2, 4, 3]
prev_indices: [-1, 0, -1, 1, 2, -1]
pos: [2, 4, 3, -1, -1, -1]

5번째:
lis: [10, 15, 30, 50]
lis_indices: [2, 4, 3, 5]
prev_indices: [-1, 0, -1, 1, 2, 3]
pos: [2, 4, 3, 5, -1, -1]


lis_length: 4
A[5]: 50
prev_indices[5]: 3
A[3]: 30
prev_indices[3]: 1
A[1]: 20
prev_indices[1]: 0
A[0]: 10

*/