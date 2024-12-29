#include <iostream>
using namespace std;

/*
N-Queen 문제
1. N x N 체스판에 N개의 퀸을 서로 공격할 수 없게 놓는 문제
2. 퀸은 가로, 세로, 대각선으로 무한정 움직일 수 있음
3. N이 주어졌을 때, N-Queen 문제의 해의 개수를 구하는 프로그램을 작성

풀이
1. 각 행에 퀸을 놓을 수 있는지 확인
2. 같은 열에 있는지, 대각선에 있는지 확인
3. 가능하다면 다음 행으로 넘어가서 재귀적으로 확인
4. N개의 퀸을 모두 놓았다면 결과값을 1 증가

backtracking
*/

int N;
int col[15]; // col[i] = j : i번째 행의 j번째 열에 퀸이 위치함
int result = 0;

bool check(int level)
{ // level행에 퀸을 놓을 수 있는지 확인
    for (int i = 0; i < level; i++)
    { // promising
        // 같은 열에 있는지, 대각선에 있는지 확인
        if (col[i] == col[level] || abs(col[level] - col[i]) == level - i)
            return false;
    }
    return true;
}

void nqueen(int x)
{
    if (x == N)
    { // N개의 퀸을 모두 놓았다면
        result++;
        return;
    }
    for (int i = 0; i < N; i++)
    { // x행 i열에 퀸을 놓을 수 있는지 확인
        col[x] = i;
        if (check(x))
            nqueen(x + 1);
        // pruning
    }
}

int main()
{
    cin >> N;
    nqueen(0);
    cout << result;
}