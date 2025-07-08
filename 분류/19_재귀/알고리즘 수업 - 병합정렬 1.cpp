#include <iostream>
#include <vector>
using namespace std;

int cnt = 0;

void merge(vector<int> &A, int left, int mid, int right, int K);

void merge_sort(vector<int> &A, int left, int right, int K)
{
    if (left < right)
    {
        int mid = (left + right) / 2;
        merge_sort(A, left, mid, K);
        merge_sort(A, mid + 1, right, K);
        merge(A, left, mid, right, K);
    }
}

void merge(vector<int> &A, int left, int mid, int right, int K)
{
    vector<int> temp;
    int i = left, j = mid + 1;

    while (i <= mid && j <= right)
    {
        if (A[i] <= A[j])
        {
            temp.push_back(A[i]);
            i++;
        }
        else
        {
            temp.push_back(A[j]);
            j++;
        }
    }

    while (i <= mid)
    {
        temp.push_back(A[i]);
        i++;
    }

    while (j <= right)
    {
        temp.push_back(A[j]);
        j++;
    }

    for (int i = left; i <= right; i++)
    {
        A[i] = temp[i - left];
        cnt++;
        if (cnt == K)
        {
            cout << A[i] << '\n';
            exit(0);
        }
    }
}

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    int N, K;
    cin >> N >> K;

    vector<int> A(N);
    for (int i = 0; i < N; i++)
    {
        cin >> A[i];
    }

    merge_sort(A, 0, N - 1, K);
    cout << -1 << '\n'; // If K-th merge is not found
    return 0;
}