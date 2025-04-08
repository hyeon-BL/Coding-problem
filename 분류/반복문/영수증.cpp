#include <iostream>
#include <vector>
using namespace std;

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    int X; // 영수증의 총 금액
    cin >> X;
    int N; // 영수증에 적힌 물건의 종류 수
    cin >> N;
    vector<pair<int, int>> items(N); // 물건의 가격과 개수
    for (int i = 0; i < N; i++)
    {
        cin >> items[i].first >> items[i].second; // 가격과 개수 입력
    }

    int total = 0; // 총 금액 계산
    for (int i = 0; i < N; i++)
    {
        total += items[i].first * items[i].second; // 가격 * 개수
    }

    if (total == X)
    {
        cout << "Yes"; // 총 금액이 영수증의 총 금액과 일치
    }
    else
    {
        cout << "No"; // 일치하지 않음
    }
}