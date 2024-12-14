#include<iostream>
#include<algorithm>
using namespace std;

bool compare(pair<int, int>& a, pair<int, int>& b) {
    if (a.second == b.second) {
        return a.first < b.first;
    }
    return a.second < b.second;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);

    int N;
    cin >> N;

    pair<int, int>* meeting = new pair<int, int>[N];
    for (int i = 0; i < N; i++) {
        cin >> meeting[i].first >> meeting[i].second;
    }

    sort(meeting, meeting + N, compare);

    int count = 0;
    int endTime = 0;

    // finish time이 가장 빠른 회의부터 시작
    for (int i = 0; i < N; i++) {
        if (meeting[i].first >= endTime) {
            endTime = meeting[i].second;
            count++;
        }
    }

    cout << count << endl;

    delete[] meeting;
    return 0;
}