#include <iostream>
#include <set>
using namespace std;

int main()
{
  cin.tie(0);
  ios::sync_with_stdio(0);

  int N;
  cin >> N;

  set<string> dancing;
  dancing.insert("ChongChong");

  pair<string, string> meeting;
  while (N--)
  {
    cin >> meeting.first >> meeting.second;
    if (dancing.find(meeting.first) != dancing.end() || dancing.find(meeting.second) != dancing.end())
    {
      dancing.insert(meeting.first);
      dancing.insert(meeting.second);
    }
  }

  cout << dancing.size() << '\n';
  return 0;
}