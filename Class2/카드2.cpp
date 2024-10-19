#include <iostream>
#include <deque>
using namespace std;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);

    int N;
    cin >> N;

    deque<int> dq;
    for (int i = 1; i <= N; i++) {
        dq.push_back(i);
    }

    while (dq.size() > 1) {
        dq.pop_front(); // 첫 번째 카드를 버림
        dq.push_back(dq.front()); // 두 번째 카드를 맨 뒤로 옮김
        dq.pop_front(); // 두 번째 카드를 덱에서 제거
    }

    cout << dq.front() << endl; // 마지막 남은 카드 출력

    return 0;
}