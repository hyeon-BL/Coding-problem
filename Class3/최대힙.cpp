#include<iostream>
#include<queue>
using namespace std;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);

    int N;
    cin >> N;

    priority_queue<int> maxHeap; // 최대힙 O(logN)
    while(N--) {
        int x;
        cin >> x;
        if (x == 0) {
            if (maxHeap.empty()) {
                cout << 0 << '\n';
                continue;
            }
            cout << maxHeap.top() << '\n';
            maxHeap.pop();
            continue;
        }
        maxHeap.push(x);
    }

}