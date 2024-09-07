#include <iostream>
#include <vector>
using namespace std;
 
int main(){
    int n, x, y;
    int count;
 
    cin >> n; // number of people
    vector<pair<int, int>> v; 
 
    for(int i = 0; i < n; i++){
        cin >> x >> y;
        v.push_back(pair<int, int>(x, y)); // pair를 vector에 넣어줌
    }
 
    for(int j = 0; j < n; j++){
        count = 1;
        for(int k = 0; k < n; k++){
            if(v[j].first < v[k].first && v[j].second < v[k].second){ // j번째 사람보다 큰 사람이 있으면 count 증가
                count++;
            }
        }
        if (j == n - 1)
        {
            cout << count;
        }
        else
        {
            cout << count << " ";
        }
    }
}