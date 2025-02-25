#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Line
{
    int a, b;
};

bool compare(const Line &l1, const Line &l2)
{ // a 오름차순 정렬
    return l1.a < l2.a;
}

vector<int> lis(const vector<Line> &arr)
{                                          // 최장 증가 부분 수열
    vector<int> dp;                        // LIS를 저장
    vector<int> cut;                       // 선분을 자르는 위치 저장
    vector<int> parent(arr.size(), -1);    // 이전 선분의 인덱스 저장
    vector<int> lis_index(arr.size(), -1); // LIS에 포함된 선분의 인덱스 저장

    for (int i = 0; i < arr.size(); i++)
    { // 이분 탐색을 이용한 LIS
        auto it = lower_bound(dp.begin(), dp.end(), arr[i].b);
        int idx = distance(dp.begin(), it);

        if (it == dp.end())
        { // 증가하는 경우
            dp.push_back(arr[i].b);
        }
        else
        { // 갱신하는 경우  -> 이분 탐색을 통해 갱신된 위치에 삽입
            *it = arr[i].b;
        }

        if (idx > 0)
        { // 이전 값이 존재하는 경우
            parent[i] = lis_index[idx - 1];
        }
        lis_index[idx] = i;
    }

    int lis_length = dp.size();
    vector<bool> in_lis(arr.size(), false);
    for (int i = lis_index[lis_length - 1]; i >= 0; i = parent[i])
    { // LIS에 포함된 선분들 체크
        in_lis[i] = true;
    }

    for (int i = 0; i < arr.size(); i++)
    { // LIS에 포함되지 않은 선분들 저장
        if (!in_lis[i])
        {
            cut.push_back(arr[i].a);
        }
    }

    return cut;
}

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    int N;
    cin >> N;
    vector<Line> lines(N);
    for (int i = 0; i < N; i++)
    {
        cin >> lines[i].a >> lines[i].b;
    }

    sort(lines.begin(), lines.end(), compare);

    vector<int> cuts = lis(lines);

    cout << cuts.size() << '\n';
    for (int i = 0; i < cuts.size(); i++)
    {
        cout << cuts[i] << '\n';
    }

    return 0;
}