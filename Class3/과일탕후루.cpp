#include <iostream>
#include <deque>
#include <algorithm>
using namespace std;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);

    int N;
    cin >> N;
    deque<int> dq;
    int cnt[10] = {0,}; // 과일 종류(1~9)
    int type = 0; // 과일 종류 수
    int result = 0;
    for (int i = 0; i < N; i++) { // 과일을 추가하고, 2개 이상이면 앞에서부터 제거하는 방법
        int x;
        cin >> x;
        dq.push_back(x);

        if (cnt[x]++ == 0) {
            ++type;
        }

        while (type > 2) {
            int friut = dq.front();
            dq.pop_front();
            if (--cnt[friut] == 0) {
                --type;
            }
        }
        
        result = max(result, static_cast<int>(dq.size())); // 최대 길이 갱신
    }

    cout << result;
    return 0;
}