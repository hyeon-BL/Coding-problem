#include<iostream>
#include<vector>
#include<algorithm> // Add this line to include the <algorithm> header
using namespace std;
int main(){
    int n, x, y;
    int count;
 
    cin >> n; // 좌표수
    vector<pair<int, int>> v; 
 
    for(int i = 0; i < n; i++){
        cin >> x >> y;
        v.push_back(pair<int, int>(y, x)); // pair를 vector에 넣어줌
    }
 
    sort(v.begin(), v.end()); // 정렬

    for (int i = 0; i < n; i++)
    {
        cout << v[i].second << " " << v[i].first << "\n";
    }
}