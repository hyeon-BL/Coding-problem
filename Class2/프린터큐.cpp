#include<iostream>
#include<queue>
using namespace std;


void printer() {
    int n, m, r;
    queue<pair<int, int>> q;
    priority_queue<int> pq;
    cin >> n >> r; // n: 문서의 개수, r: 몇 번째로 인쇄되었는지 궁금한 문서의 위치
    for (int i = 0; i < n; i++) {
        cin >> m; // m: 문서의 중요도
        q.push({ i, m });
        pq.push(m);
    }
    while (!q.empty()) {
        int idx = q.front().first;
        int val = q.front().second;
        q.pop();

        if (val == pq.top()) {
            pq.pop();
            if (idx == r) {
                cout << n - q.size() << endl;
                break;
                if (i == n - 1) {
                    cout << n - q.size();
                }
            }
        else {
            q.push({ idx, val });
            }
        }
    }
}



int main() {
    int test_n;
    static arr[test_n];
    cin >> test_n; // test_n: 총 테스트 케이스의 수
    for (int i = 0; i < test_n; i++) {
        printer();
    }
}