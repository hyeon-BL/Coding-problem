#include <iostream>
#include <list> // list를 사용하기 위해 추가
#include <numeric> // accumulate를 사용하기 위해 추가
using namespace std;
int main() {
    int n, level, rmv = 0;
    list<int> lst;
    cin >> n;
    
    if (n == 0) {
        cout << 0;
    }
    else {
        for (int i = 0; i < n; i++) {
            cin >> level;
            lst.push_back(level);
        }
        lst.sort();
        rmv = floor(n * 0.15 + 0.5); // 15% 제거 (반올림)
        for (int i = 0; i < rmv; i++) {
            lst.pop_front();
            lst.pop_back();
        }
        float sum = accumulate(lst.begin(), lst.end(), 0); // accumulate를 사용하여 list의 합을 구함
        cout << floor(sum / (n - 2 * rmv) + 0.5);
    }
}