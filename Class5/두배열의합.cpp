#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    int T, N, M; // 부 배열의 합, 배열 A, B의 크기
    cin >> T;
    cin >> N;
    vector<int> A(N);
    for (int i = 0; i < N; i++)
    {
        cin >> A[i];
    }
    cin >> M;
    vector<int> B(M);
    for (int i = 0; i < M; i++)
    {
        cin >> B[i];
    }

    vector<int> sumA, sumB;
    for (int i = 0; i < N; i++)
    { // A의 부 배열의 합을 구함
        int sum = 0;
        for (int j = i; j < N; j++)
        {
            sum += A[j];
            sumA.push_back(sum);
        }
    }
    for (int i = 0; i < M; i++)
    { // B의 부 배열의 합을 구함
        int sum = 0;
        for (int j = i; j < M; j++)
        {
            sum += B[j];
            sumB.push_back(sum);
        }
    }

    sort(sumA.begin(), sumA.end());
    sort(sumB.begin(), sumB.end());

    long long count = 0;
    for (int i = 0; i < sumA.size(); i++)
    { // A의 부 배열의 합을 하나씩 꺼내서 T에서 뺀 값이 B의 부 배열의 합에 있는지 확인
        int target = T - sumA[i];
        count += upper_bound(sumB.begin(), sumB.end(), target) - lower_bound(sumB.begin(), sumB.end(), target); // target과 같은 값이 몇 개인지
    }
    cout << count;
}