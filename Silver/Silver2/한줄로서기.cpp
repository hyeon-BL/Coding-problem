#include <iostream>
#include <vector>
#include <list>
using namespace std;

/*
list : 삽입, 삭제가 O(1)이므로 시간복잡도가 낮다
vector : 삽입, 삭제가 O(N)이므로 시간복잡도가 높다
*/

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    int N;
    cin >> N;
    vector<int> line(N);
    for (int i = 0; i < N; i++)
    {
        cin >> line[i];
    }
    list<int> arr;
    for (int i = 0; i < N; i++)
    {
        arr.push_back(i);
    }

    vector<int> order(N);
    for (int i = 1; i <= N; i++)
    {
        auto it = arr.begin();
        advance(it, line[i - 1]); // line[i-1]번째 위치로 이동
        order[*it] = i;
        arr.erase(it);
    }

    for (int i = 0; i < N; i++)
    {
        cout << order[i] << " ";
    }
}