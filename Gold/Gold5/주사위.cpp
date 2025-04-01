#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#include <numeric>
using namespace std;

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    long long N; // 정육면체 한변의 길이(long long으로 해야 result가 overflow 안됨)
    cin >> N;

    int arr[6]; // 각 면의 숫자
    for (int i = 0; i < 6; i++)
    {
        cin >> arr[i]; // 각 면의 숫자 입력
    }

    // 가장 작은 면의 숫자
    int one_face_min = *min_element(arr, arr + 6);
    int two_face_min = INT_MAX;
    int three_face_min = INT_MAX;

    // 두번째 가장 작은 면의 숫자: 두 면이 서로 마주보지 않는 경우
    vector<pair<int, int>> opposite = {{0, 5}, {1, 4}, {2, 3}}; // 마주보는 면 쌍
    for (int i = 0; i < 6; i++)
    {
        for (int j = i + 1; j < 6; j++)
        {
            if (find(opposite.begin(), opposite.end(), make_pair(i, j)) == opposite.end() &&
                find(opposite.begin(), opposite.end(), make_pair(j, i)) == opposite.end())
            { // 마주보지 않는다면
                two_face_min = min(two_face_min, arr[i] + arr[j]);
            }
        }
    }

    // 세번째 가장 작은 면의 숫자: 세 면이 모서리에서 만나는 경우
    vector<vector<int>> three_faces = {{0, 1, 2}, {0, 1, 3}, {0, 4, 2}, {0, 4, 3}, {5, 1, 2}, {5, 1, 3}, {5, 4, 2}, {5, 4, 3}};
    for (auto &faces : three_faces)
    { // 각 모서리에서 만나는 세 면
        three_face_min = min(three_face_min, arr[faces[0]] + arr[faces[1]] + arr[faces[2]]);
    }

    long long result = 0;
    if (N == 1)
    {
        // 정육면체가 1x1x1일 때
        result = accumulate(arr, arr + 6, 0) - *max_element(arr, arr + 6);
    }
    else
    {
        // 코너 (3면이 보이는 경우)
        result += 4 * (long long)three_face_min;
        // 모서리 (2면이 보이는 경우)
        result += (8 * N - 12) * (long long)two_face_min;
        // 면 (1면이 보이는 경우)
        result += (5 * N * N - 16 * N + 12) * (long long)one_face_min;
    }

    cout << result;
}