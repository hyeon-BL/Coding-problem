#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/*
1. 두 배열을 입력받아 각각의 배열의 원소들을 더한 값을 저장하는 배열 AB와 CD를 생성한다.
2. AB와 CD를 정렬한다.
3. AB의 i번째 원소와 CD의 n - i - 1번째 원소를 더했을 때 0이라면
AB의 i번째 원소와 CD의 n - i - 1번째 원소를 더했을 때 0이 되는 쌍이 존재한다는 의미이므로 cnt를 1 증가시킨다.
4. cnt를 출력한다.
*/

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    int n;
    cin >> n;
    vector<vector<long long>> arr(n, vector<long long>(4));
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i][0] >> arr[i][1] >> arr[i][2] >> arr[i][3];
    }
    vector<long long> AB, CD;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            AB.push_back(arr[i][0] + arr[j][1]);
            CD.push_back(arr[i][2] + arr[j][3]);
        }
    }

    sort(AB.begin(), AB.end()); // AB를 정렬 -> 캐시 효율성을 위해(유사한 값들이 모여있기 때문에)
    sort(CD.begin(), CD.end()); // CD를 정렬

    long long cnt = 0;
    for (int i = 0; i < AB.size(); i++)
    { // AB의 i번째 원소와 CD의 n - i - 1번째 원소를 더했을 때 0이라면
        cnt += upper_bound(CD.begin(), CD.end(), -AB[i]) - lower_bound(CD.begin(), CD.end(), -AB[i]);
    }

    cout << cnt;
}

/*
반례 :
6
-45 0 0 -16
-42 -27 0 0
-26 0 -37 0
-34 0 -35 -46
0 -38 -10 0
-32 -54 -6 0
=> 더해서 0이 되는 AB와 CD의 쌍 조합이 여러개 존재할 수 있음


2
0 2 -2 0
0 2 -2 0
=> AB

+
long long 범위 주의(4000^4 = 256,000,000,000,000)
*/