#include<iostream>
using namespace std;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);
    
    int N, count = 0;
    int arr[100];
    int prime[1000];

    for (int i=0;i<=1000;i++) {
        if (i == 0 || i == 1) {
            prime[i] = 0;
            continue;
        }
        prime[i] = 1;
    }

    for (int i=2; i<=1000; i++) {
        if (prime[i] == 0) {
            continue;
        }
        for (int j=i+i; j<=1000; j+=i) {
            prime[j] = 0;
        }
    }

    cin >> N;
    for (int i=0; i<N; i++) {
        cin >> arr[i];
    }

    for (int i=0; i<N; i++) {
        if (prime[arr[i]] == 1) {
            count++;
        }
    }
    cout << count;

}