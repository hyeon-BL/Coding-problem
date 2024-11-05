#include<iostream>
using namespace std;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);

    int N, M;
    cin >> N;
    cin >> M;
    int* arr = new int[N];
    int* prefixSum = new int[N + 1];
    prefixSum[0] = 0;

    for(int i = 0; i < N; i++) { // O(N)
        cin >> arr[i];
        prefixSum[i + 1] = prefixSum[i] + arr[i]; // N개의 수를 입력받으면서 누적합을 구함
    }

    while(M--) { // O(M)
        int i, j;
        cin >> i;
        cin >> j;
        cout << prefixSum[j] - prefixSum[i - 1] << '\n'; // 각 자리에 해당하는 누적합을 이용해 구간합을 구함
    }

    delete[] arr;
    delete[] prefixSum;
}