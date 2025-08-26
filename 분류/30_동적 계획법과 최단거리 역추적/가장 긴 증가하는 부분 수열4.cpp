#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    int N;
    cin >> N;

    vector<int> A(N);
    vector<int> lis(N, 1);
    vector<int> track(N, -1);
    for (int i = 0; i < N; i++)
        cin >> A[i];

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (A[j] < A[i] && lis[j] + 1 > lis[i])
            {
                lis[i] = lis[j] + 1;
                track[i] = j;
            }
        }
    }

    int idx = max_element(lis.begin(), lis.end()) - lis.begin();
    cout << lis[idx] << "\n";

    vector<int> result;
    for (int i = idx; i != -1; i = track[i])
        result.push_back(A[i]);

    reverse(result.begin(), result.end());

    for (int x : result)
        cout << x << " ";
    return 0;
}