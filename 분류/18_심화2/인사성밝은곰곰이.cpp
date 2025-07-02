#include<iostream>
#include<set>
using namespace std;

int main() {
  cin.tie(0);
  ios::sync_with_stdio(0);

  int N;
  cin >> N;

  set<string> names;
  int cnt = 0;
  while(N--) {
    string chat;
    cin >> chat;
    if (chat == "ENTER") {
      cnt += names.size();
      names.clear();
      continue;
    }

    names.insert(chat);
  }
  cnt += names.size();

  cout << cnt << '\n';
  return 0;
}
