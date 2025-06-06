#include <iostream>
#include <vector>
using namespace std;

long long mod = 1'000'000'007;

vector<long long> arr;
vector<long long> tree;

long long init(int node, int start, int end)
{ // 세그먼트 트리: 구간 곱 구하기(logN) 자료구조
    if (start == end)
    {
        return tree[node] = arr[start];
    }
    int mid = (start + end) / 2;
    return tree[node] = init(node * 2, start, mid) * init(node * 2 + 1, mid + 1, end) % mod;
}

long long multiply(int node, int start, int end, int left, int right)
{ // 구간 합 구하기
    if (left > end || right < start)
        return 1;
    if (left <= start && end <= right)
        return tree[node];
    int mid = (start + end) / 2;
    return multiply(node * 2, start, mid, left, right) * multiply(node * 2 + 1, mid + 1, end, left, right) % mod;
}

void update(int node, int start, int end, int index, long long newValue)
{ // 특정 인덱스 값 변경
    if (index < start || index > end)
        return;
    tree[node] = newValue;
    if (start == end)
        return;
    int mid = (start + end) / 2;
    update(node * 2, start, mid, index, newValue);
    update(node * 2 + 1, mid + 1, end, index, newValue);
    tree[node] = tree[node * 2] * tree[node * 2 + 1] % mod; // 갱신
}

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    int N, M, K; // N: 수의 개수, M: 변경이 일어나는 횟수, K: 구간의 곱을 구하는 횟수
    cin >> N >> M >> K;

    arr.resize(N + 1);
    tree.resize(4 * N);

    for (int i = 1; i <= N; ++i)
    {
        cin >> arr[i];
    }

    // 세그먼트 트리 초기화
    init(1, 1, N);

    for (int i = 0; i < M + K; ++i)
    {
        long long a, b, c;
        cin >> a >> b >> c;

        if (a == 1)
        {
            // b번째 수를 c로 변경
            arr[b] = c;
            update(1, 1, N, b, c);
        }
        else
        { // a == 2
            // b번째 수부터 c번째 수까지의 곱을 구하기
            cout << multiply(1, 1, N, b, c) << '\n';
        }
    }
}