#include <iostream>
#include <vector>
using namespace std;

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    int N, S;
    vector<int> v;
    cin >> N >> S;
    v.resize(N);
    for (int i = 0; i < N; i++)
    {
        cin >> v[i];
    }

    int min_len = 100001;
    int start = 0, end = 0;
    int sum = v[0];
    while (start <= end && end < N)
    { // 2 pointer - if sum < S, end++; if sum == S, end++; if sum > S, start++
        if (sum < S)
        {
            end++;
            sum += v[end];
        }
        else if (sum == S)
        {
            min_len = min(min_len, end - start + 1);
            end++;
            sum += v[end];
        }
        else if (sum > S)
        {
            min_len = min(min_len, end - start + 1); // sum 이상인 값
            sum -= v[start];
            start++;
        }
    }
    cout << (min_len == 100001 ? 0 : min_len);
}