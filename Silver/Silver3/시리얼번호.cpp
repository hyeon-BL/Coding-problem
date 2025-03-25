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
    vector<string> arr(N);
    for (int i = 0; i < N; i++)
    {
        cin >> arr[i];
    }

    sort(arr.begin(), arr.end(), [](string a, string b)
         {
        if (a.size() == b.size()) {
            int aSum = 0, bSum = 0;
            for (int i = 0; i < a.size(); i++) {
                if (a[i] >= '0' && a[i] <= '9' )
                    aSum += a[i] - '0';
                if (b[i] >= '0' && b[i] <= '9')
                    bSum += b[i] - '0';
            }
            if (aSum != bSum)
                return aSum < bSum;
            else {
                for (int i = 0; i < a.size(); i++) {
                    if (a[i] != b[i])
                        return a[i] < b[i];
                }
            }

        }
        return a.size() < b.size(); });

    for (int i = 0; i < N; i++)
    {
        cout << arr[i] << "\n";
    }
}