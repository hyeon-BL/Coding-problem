#include<iostream>
#include<queue>
#include<functional>
using namespace std;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);

    int N;
    cin >> N;

    auto cmp = [](pair<int, int> left, pair<int, int> right) {
        if (left.first == right.first) {
            return left.second > right.second; // Push negative integers first if absolute values are the same
        }
        return left.first > right.first;
    };

    priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(cmp)> absHeap(cmp);

    while(N--) {
        int x;
        cin >> x;
        if (x == 0) {
            if (absHeap.empty()) {
                cout << "result : " << 0 << '\n';
            } else {
                cout << "result : " << absHeap.top().second << '\n';
                absHeap.pop();
            }
        } else {
            absHeap.push({abs(x), x}); // Push pair of absolute value and original value
        }
    }

    return 0;
}