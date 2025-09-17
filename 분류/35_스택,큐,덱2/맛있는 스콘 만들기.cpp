#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <climits>
#include <deque>
using namespace std;

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    int N, M, C, D;
    cin >> N >> M >> C >> D;
    vector<int> b(N);
    for (int i = 0; i < N; i++)
        cin >> b[i];

    // dp: 1부터 M까지 인덱스 사용. 초기 상태: 자유롭게 조정 가능.
    vector<int> dp(M + 1, INT_MIN), new_dp(M + 1, INT_MIN);
    for (int pos = 1; pos <= M; pos++)
        dp[pos] = M - abs(b[0] - pos);

    // R: 그룹 내 인덱스 차이 상한 (allowed move: d = k * C, |d| <= D)
    int R = D / C;

    // t: 시간 단계 1부터 N-1
    for (int t = 1; t < N; t++)
    {
        // new_dp 초기화
        fill(new_dp.begin(), new_dp.end(), INT_MIN);

        // 각 mod 그룹 별로 처리: u = r, r+C, r+2C, ... (단, 1 <= u <= M)
        // r는 1~min(C, M)
        for (int r = 1; r <= min(C, M); r++)
        {
            vector<int> posList;
            // posList: 해당 그룹에 속하는 실제 위치
            for (int pos = r; pos <= M; pos += C)
                posList.push_back(pos);
            int gSize = posList.size();
            if (gSize == 0)
                continue;

            // A[i] = dp[ posList[i] ] + M   (dp 에 보정을 더한 값)
            vector<int> A(gSize);
            for (int i = 0; i < gSize; i++)
                A[i] = dp[posList[i]] == INT_MIN ? INT_MIN : dp[posList[i]] + M;

            // sliding window maximum over indices j with |i - j| <= R.
            // 각 i에 대해 window = [max(0, i-R), min(gSize-1, i+R)]
            vector<int> windowMax(gSize, INT_MIN);
            deque<int> dq; // store indices, maintain decreasing order of A[]

            // 초기 윈도우: i=0의 경우, window = [0, min(gSize-1, R)]
            int rightBound = min(gSize - 1, R);
            for (int j = 0; j <= rightBound; j++)
            {
                while (!dq.empty() && A[j] >= A[dq.back()])
                    dq.pop_back();
                dq.push_back(j);
            }
            // 모든 i에 대해 deque를 업데이트: 오른쪽 경계는 i+R, 왼쪽 경계는 i-R
            for (int i = 0; i < gSize; i++)
            {
                // 왼쪽 경계: i - R
                int leftBound = i - R;
                if (leftBound < 0)
                    leftBound = 0;
                // 오른쪽 경계: i + R
                int newRight = i + R;
                if (newRight >= gSize)
                    newRight = gSize - 1;
                // dq.front()가 윈도우 밖인 경우 제거
                while (!dq.empty() && dq.front() < leftBound)
                    dq.pop_front();
                // 만약 i==0, 이미 초기 윈도우 처리했으므로,
                // for i>=1, 새로운 오른쪽 인덱스: 이전 윈도우에는 newRight(i-1) = min(gSize-1, i-1+R)
                // 현재 윈도우 오른쪽 경계 증가분: if (i+R > (i-1+R)) 추가 index newRight if 변화가 있다.
                if (i > 0)
                {
                    int prevRight = min(gSize - 1, (i - 1) + R);
                    if (newRight > prevRight)
                    {
                        // new indices: from prevRight+1 to newRight
                        for (int j = prevRight + 1; j <= newRight; j++)
                        {
                            while (!dq.empty() && A[j] >= A[dq.back()])
                                dq.pop_back();
                            dq.push_back(j);
                        }
                    }
                }
                // window maximum for i:
                windowMax[i] = A[dq.front()];
            }

            // 이제 각 그룹에서 좌표 posList[i]에 대해 new_dp[ posList[i] ]를 계산
            // new_dp[u] = windowMax[i] + correction, where correction =
            //    (u - b[t])  if u <= b[t], or (b[t] - u) if u >= b[t]
            for (int i = 0; i < gSize; i++)
            {
                int u = posList[i];
                if (windowMax[i] == INT_MIN)
                    continue; // 가능한 이전 상태 없음.
                if (u <= b[t])
                    new_dp[u] = max(new_dp[u], windowMax[i] + u - b[t]);
                else // u > b[t]
                    new_dp[u] = max(new_dp[u], windowMax[i] + b[t] - u);
            }
        }
        dp.swap(new_dp);
    }

    int ans = INT_MIN;
    for (int pos = 1; pos <= M; pos++)
        ans = max(ans, dp[pos]);
    cout << ans;
    return 0;
}

/*
시간초과: 25000 * 25000 * moves.size() = 6.25억 * moves.size()


#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <climits>
using namespace std;

int main()
{
    int N, M, C, D;
    cin >> N >> M >> C >> D;
    vector<int> b(N);
    for (int i = 0; i < N; i++)
        cin >> b[i];

    // [-D, D] 범위에서 C의 배수인 이동 d 미리 구해두기
    vector<int> moves;
    for (int d = -D; d <= D; d++)
    {
        if (d % C == 0)
            moves.push_back(d);
    }

    // dp: 1부터 M까지 인덱스 사용. 시간=0에서는 자유롭게 조정 가능.
    vector<int> dp(M + 1, INT_MIN), new_dp(M + 1, INT_MIN);
    for (int temp = 1; temp <= M; temp++)
        dp[temp] = M - abs(b[0] - temp);

    // 1~N-1 시간에 대한 DP 전이
    for (int t = 1; t < N; t++)
    {
        fill(new_dp.begin(), new_dp.end(), INT_MIN);
        for (int v = 1; v <= M; v++)
        {
            if (dp[v] == INT_MIN)
                continue;
            for (int d : moves)
            {
                int u = v + d;
                if (u < 1 || u > M)
                    continue;
                new_dp[u] = max(new_dp[u], dp[v] + (M - abs(b[t] - u)));
            }
        }
        dp.swap(new_dp);
    }

    int ans = INT_MIN;
    for (int temp = 1; temp <= M; temp++)
        ans = max(ans, dp[temp]);

    cout << ans;
    return 0;
}

*/