#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);

    int N;
    cin >> N;
    
    vector<int> v, c; // 벡터 선언
    for (int i=0; i<N; i++){
        int num;
        cin >> num;
        v.push_back(num); // 벡터에 추가
    }
    c = v; // 복사
    sort(v.begin(), v.end()); // 오름차순 정렬

    v.erase(unique(v.begin(), v.end()), v.end()); // 중복 제거

    for (int i=0; i<N; i++) {
        int idx = lower_bound(v.begin(), v.end(), c[i]) - v.begin(); // v에서 c[i]의 위치
        cout << idx << " "; // idx만큼 작은수가 앞에 존재
    }
}