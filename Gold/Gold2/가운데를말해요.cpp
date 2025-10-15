#include<iostream>
#include<vector>
#include<queue>
using namespace std;

int main() {
  cin.tie(0);
  ios::sync_with_stdio(0);

  int N;
  cin >> N;
  
  priority_queue<int> max_heap;
  priority_queue<int, vector<int>, greater<int>> min_heap;

  for (int i = 0; i < N; i++) {
    int num;
    cin >> num;

    if (max_heap.size() == min_heap.size()) {
      max_heap.push(num);
    } else {
      min_heap.push(num);
    }

    if (!max_heap.empty() && !min_heap.empty() && max_heap.top() > min_heap.top()) {
      int max_val = max_heap.top();
      int min_val = min_heap.top();
      max_heap.pop();
      min_heap.pop();
      max_heap.push(min_val);
      min_heap.push(max_val);
    }
    
    cout << max_heap.top() << '\n';
  }
}
