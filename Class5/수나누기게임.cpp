#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Player
{
    int card;
    int score;
};

int main()
{
    int N;
    cin >> N;
    vector<Player> players(N + 1);

    for (int i = 1; i <= N; i++)
    {
        cin >> players[i].card;
        players[i].score = 0;
    }

    // 플레이어가 가진 카드의 인덱스 저장
    vector<int> card_index(1'000'002, -1);
    for (int i = 1; i <= N; i++)
    { // O(N)
        card_index[players[i].card] = i;
    }

    // 점수 계산
    for (int i = 1; i <= N; i++)
    { // 플레이어 i의 카드에 대해
        for (int j = 2 * players[i].card; j <= 1'000'001; j += players[i].card)
        { // 2배부터 시작하여 N까지 증가
            if (card_index[j] != -1)
            { // 카드가 존재할 경우
                players[i].score++;
                players[card_index[j]].score--;
            }
        }
    }

    // Output results
    for (int i = 1; i <= N; i++)
    {
        cout << players[i].score << ' ';
    }

    return 0;
}