#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    while (true)
    {
        int n; // 직사각형의 개수
        cin >> n;
        if (n == 0)
            break;                    // 종료 조건
        vector<long long> heights(n); // 직사각형의 높이를 저장할 벡터
        for (int i = 0; i < n; ++i)
        {
            cin >> heights[i]; // 직사각형의 높이 입력
        }

        long long maxArea = 0; // 최대 면적 초기화
        stack<int> indices;    // 인덱스를 저장할 스택
        for (int i = 0; i <= n; ++i)
        {
            long long height = (i == n) ? 0 : heights[i]; // 현재 높이
            while (!indices.empty() && heights[indices.top()] > height)
            {
                int h = indices.top();                                         // 스택에서 인덱스 가져오기
                indices.pop();                                                 // 스택에서 제거
                long long width = indices.empty() ? i : i - indices.top() - 1; // 너비 계산
                maxArea = max(maxArea, heights[h] * width);                    // 최대 면적 갱신
            }
            indices.push(i); // 현재 인덱스 추가
        }
        cout << maxArea << '\n'; // 결과 출력
    }
}