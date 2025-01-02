#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    int N, M;
    vector<int> sequenceA, sequenceB;
    cin >> N;
    sequenceA.resize(N);
    for (int i = 0; i < N; i++)
    {
        cin >> sequenceA[i];
    }
    cin >> M;
    sequenceB.resize(M);
    for (int i = 0; i < M; i++)
    {
        cin >> sequenceB[i];
    }

    // Build the lexicographically latest subsequence using a greedy approach
    vector<int> result;
    int i = 0, j = 0;

    while (i < N) // N <= 100
    {
        int max_val = -1;
        int max_idx_a = -1;
        int max_idx_b = -1;

        // Find the largest matching number from current positions
        for (int x = i; x < N; x++) // N <= 100
        {
            for (int y = j; y < M; y++) // M <= 100
            {
                if (sequenceA[x] == sequenceB[y] && sequenceA[x] > max_val)
                { // Greedy: Choose the largest number
                    max_val = sequenceA[x];
                    max_idx_a = x;
                    max_idx_b = y;
                }
            }
        }

        if (max_val == -1)
            break; // No more matches found

        result.push_back(max_val); // Add the largest matching number to the result
        i = max_idx_a + 1;
        j = max_idx_b + 1;
    }

    // Print the result
    if (result.empty())
    {
        cout << "0\n";
    }
    else
    {
        cout << result.size() << '\n';
        for (int num : result)
        {
            cout << num << ' ';
        }
    }

    return 0;
}