#include<iostream>
#include<queue>
#include<unordered_map>
using namespace std;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);

    int T, k, n;
    char oper;
    cin >> T;
    while(T--) {
        cin >> k;
        priority_queue<long long> maxHeap; // default: maxHeap
        priority_queue<long long, vector<long long>, greater<long long>> minHeap; // minHeap
        unordered_map<long long, int> countMap; // to keep track of counts

        while(k--) {
            cin >> oper >> n; // I: insert, D: delete
            if(oper == 'I') {
                maxHeap.push(n);
                minHeap.push(n);
                countMap[n]++;
            } else {
                if(n == 1) { // delete max
                    while(!maxHeap.empty() && countMap[maxHeap.top()] == 0) { // update maxHeap accordingly
                        maxHeap.pop();
                    }
                    if(!maxHeap.empty()) {
                        countMap[maxHeap.top()]--;
                        maxHeap.pop();
                    }
                } else { // delete min
                    while(!minHeap.empty() && countMap[minHeap.top()] == 0) { // update minHeap accordingly
                        minHeap.pop();
                    }
                    if(!minHeap.empty()) {
                        countMap[minHeap.top()]--;
                        minHeap.pop();
                    }
                }
            }
        }

        while(!maxHeap.empty() && countMap[maxHeap.top()] == 0) {
            maxHeap.pop();
        }
        while(!minHeap.empty() && countMap[minHeap.top()] == 0) {
            minHeap.pop();
        }

        if(maxHeap.empty() || minHeap.empty()) {
            cout << "EMPTY\n";
        } else {
            cout << maxHeap.top() << ' ' << minHeap.top() << '\n';
        }
    }
    return 0;
}