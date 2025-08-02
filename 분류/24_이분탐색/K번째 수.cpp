#include <iostream>
using namespace std;

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    long long N, K;
    cin >> N >> K;

    // set the range for binary search
    long long left = 1, right = N * N;
    long long answer = 0;

    // parametric binary search
    // find the K-th smallest number in the multiplication table of size N x N
    while (left <= right)
    {
        long long mid = (left + right) / 2;
        long long count = 0;

        // count how many numbers are less than or equal to mid
        for (long long i = 1; i <= N; i++)
        { // 1. Condition
            count += (N > mid / i ? mid / i : N);
        }

        if (count < K)
        {                   // 2. Increment
            left = mid + 1; // search in the upper half
        }
        else
        {                 // 3. Update & Decrement
            answer = mid; // update answer and search in the lower half
            right = mid - 1;
        }
    }

    cout << answer << "\n";
}