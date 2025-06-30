#include<iostream>
using namespace std;

int factorial(int n) {
  if(n == 0) {
    return 1;
  }
  return n * factorial(n-1);
}

int main() {
  cin.tie(0);
  ios::sync_with_stdio(0);

  int N;
  cin >> N;

  int result = factorial(N);
  cout << result << '\n';
  return 0;
}
