#include <iostream>
#include <vector>
using namespace std;

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    int N;
    cin >> N;
    vector<int> prevMax(3), currMax(3);
    vector<int> prevMin(3), currMin(3);
    // 전부 저장하지 않고 이전 값만 저장하여 메모리 절약

    for (int i = 0; i < N; i++)
    {
        vector<int> v(3);
        cin >> v[0] >> v[1] >> v[2];

        if (i == 0)
        {
            prevMax = v;
            prevMin = v;
        }
        else
        {
            currMax[0] = v[0] + max(prevMax[0], prevMax[1]);
            currMax[1] = v[1] + max(max(prevMax[0], prevMax[1]), prevMax[2]);
            currMax[2] = v[2] + max(prevMax[1], prevMax[2]);

            currMin[0] = v[0] + min(prevMin[0], prevMin[1]);
            currMin[1] = v[1] + min(min(prevMin[0], prevMin[1]), prevMin[2]);
            currMin[2] = v[2] + min(prevMin[1], prevMin[2]);

            prevMax = currMax;
            prevMin = currMin;
        }
    }

    cout << max(max(prevMax[0], prevMax[1]), prevMax[2]) << ' ' << min(min(prevMin[0], prevMin[1]), prevMin[2]);
}

/*
#include <iostream>
#include <vector>
using namespace std;

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    int N;
    cin >> N;
    vector<vector<int>> v(N, vector<int>(3));
    for (int i = 0; i < N; i++)
    {
        cin >> v[i][0] >> v[i][1] >> v[i][2];
    }
    vector<vector<int>> dpM(N, vector<int>(3)); // 100,000 * 3 * 4B = 1.2MB
    vector<vector<int>> dpm(N, vector<int>(3)); // 100,000 * 3 * 4B = 1.2MB -> 메모리 초과

    dpM[0][0] = v[0][0];
    dpM[0][1] = v[0][1];
    dpM[0][2] = v[0][2];

    dpm[0][0] = v[0][0];
    dpm[0][1] = v[0][1];
    dpm[0][2] = v[0][2];

    for (int i = 1; i < N; i++)
    {
        dpM[i][0] = v[i][0] + max(dpM[i - 1][0], dpM[i - 1][1]);
        dpM[i][1] = v[i][1] + max(max(dpM[i - 1][0], dpM[i - 1][1]), dpM[i - 1][2]);
        dpM[i][2] = v[i][2] + max(dpM[i - 1][1], dpM[i - 1][2]);
        dpm[i][0] = v[i][0] + min(dpm[i - 1][0], dpm[i - 1][1]);
        dpm[i][1] = v[i][1] + min(min(dpm[i - 1][0], dpm[i - 1][1]), dpm[i - 1][2]);
        dpm[i][2] = v[i][2] + min(dpm[i - 1][1], dpm[i - 1][2]);
    }
    cout << max(max(dpM[N - 1][0], dpM[N - 1][1]), dpM[N - 1][2]) << ' ' << min(min(dpm[N - 1][0], dpm[N - 1][1]), dpm[N - 1][2]);
}
*/