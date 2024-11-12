#include<iostream>
#include<queue>
using namespace std;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);

    int N;
    cin >> N;

    priority_queue<int, vector<int>, greater<int>> minHeap; // 최소힙 O(logN)
    while(N--) {
        int x;
        cin >> x;
        if (x == 0) {
            if (minHeap.empty()) {
                cout << 0 << '\n';
                continue;
            }
            cout << minHeap.top() << '\n';
            minHeap.pop();
            continue;
        }
        minHeap.push(x);
    }

}