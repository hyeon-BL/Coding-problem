#include <iostream>
#include <deque>
#include <vector>
using namespace std;

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    int N; // N: 자료구조 개수
    cin >> N;

    deque<int> dq;        // 덱
    vector<int> types(N); // 자료구조 타입 저장
    for (int i = 0; i < N; i++)
    {
        int type;
        cin >> type;
        types[i] = type; // 자료구조 타입 저장
    }

    for (int i = 0; i < N; i++)
    {
        int value;
        cin >> value;
        if (types[i] == 0)
            dq.push_front(value); // 덱에 값 추가
    }

    int M;
    cin >> M; // M: 삽입할 수열 길이
    for (int i = 0; i < M; i++)
    {
        int x;
        cin >> x;

        dq.push_back(x);           // 덱에 값 삽입
        cout << dq.front() << ' '; // 덱 앞에서 값 꺼내기
        dq.pop_front();            // 덱 앞에서 값 제거
    }
}

// int main()
// {
//     cin.tie(0);
//     ios::sync_with_stdio(0);

//     int N; // N: 자료구조 개수
//     cin >> N;

//     vector<deque<int>> deques(N); // 덱 벡터 선언
//     vector<int> types(N);         // 자료구조 타입 저장
//     for (int i = 0; i < N; i++)
//     {
//         int type;
//         cin >> type;
//         types[i] = type; // 자료구조 타입 저장
//     }

//     for (int i = 0; i < N; i++)
//     {
//         int value;
//         cin >> value;
//         deques[i].push_back(value); // 덱에 값 추가
//     }

//     int M;
//     cin >> M; // M: 삽입할 수열 길이
//     for (int i = 0; i < M; i++)
//     {
//         int x;
//         cin >> x;

//         for (int j = 0; j < N; j++)
//         {
//             if (types[j] == 0)
//             {                           // 큐 동작
//                 deques[j].push_back(x); // 덱 뒤에 값 삽입
//                 x = deques[j].front();  // 덱 앞에서 값 꺼내기
//                 deques[j].pop_front();  // 덱 앞에서 값 제거
//             }
//             else if (types[j] == 1)
//             {                           // 스택 동작
//                 deques[j].push_back(x); // 덱 뒤에 값 삽입
//                 x = deques[j].back();   // 덱 뒤에서 값 꺼내기
//                 deques[j].pop_back();   // 덱 뒤에서 값 제거
//             }
//         }
//         cout << x << ' '; // 마지막에 꺼낸 값 출력
//     }
// }