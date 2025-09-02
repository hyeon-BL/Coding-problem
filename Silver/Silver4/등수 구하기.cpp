#include <iostream>
#include <vector>
using namespace std;

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    int N, S, P;
    cin >> N >> S >> P;

    if (N == 0)
    { // 비어있는 경우
        cout << 1;
        return 0;
    }

    vector<int> scores(N);
    for (int i = 0; i < N; i++)
    {
        cin >> scores[i];
    }

    if (N == P && scores[N - 1] >= S)
    { // 리스트가 가득 차고, 새로운 점수가 기존 점수보다 크거나 같은 경우
        cout << -1;
        return 0;
    }

    int rank = 1;
    for (int i = 0; i < N && scores[i] > S; i++)
    { // 기존 점수가 새 점수보다 큰 경우
        rank++;
    }

    if (rank > P)
    { // 랭크가 P를 초과하는 경우
        cout << -1;
    }
    else
    {
        cout << rank;
    }

    return 0;
}