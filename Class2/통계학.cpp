#include <iostream>
#include <cmath>
#include <list>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int N, min, max, most = 0, t = 0, prev = 0, result = 0;
    double sum = 0;
    list<int> cnt;
    list<int> lst;
    vector<pair<int, int>> l;
    cin >> N; // N은 입력받을 정수의 개수, 홀수
    for (int i = 0; i < N; i++) {
        cin >> t;
        lst.push_back(t);
    }
    lst.sort();
    for (auto i = lst.begin(); i != lst.end(); i++) {
        sum += *i;
        if (i == lst.begin()) {
            prev = *i;
            l.push_back({*i, 1});
        }
        else {
            if (prev == *i) {
                l.back().second++;
            }
            else {
                l.push_back({*i, 1});
                prev = *i;
            }
        }
    }
    sort(l.begin(), l.end(), [](const pair<int, int>& a, const pair<int, int>& b) {
        return a.second > b.second || (a.second == b.second && a.first < b.first);
    }); // 빈도수가 높은 순으로 정렬
    most = l.front().second;
    for (auto i = l.begin(); i != l.end(); i++) {
        if (i->second == most) {
            t = i->first;
            cnt.push_back(t);
        }
    }
    cnt.sort();

    min = lst.front();
    max = lst.back();

    result = round(sum / N);
    if (result == -0) {
        cout << 0 << endl;
    }
    else {
        cout << result << endl;
    }
    auto it = lst.begin();
    advance(it, N / 2);
    cout << *it << endl;
    if (cnt.size() > 1) {
        auto i1 = cnt.begin();
        advance(i1, 1);
        cout << *i1 << endl;
    }
    else {
        cout << *cnt.begin() << endl;
    }
    cout << max - min << endl;

    return 0;
}