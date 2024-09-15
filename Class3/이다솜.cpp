#include<iostream>
#include<map>
#include<string>
using namespace std;

int main() {
    cin.tie(0); // cin과 cout의 묶음을 풀어줌 -> cin만
	ios::sync_with_stdio(0); // 시간 초과 방지 -> C와 C++의 버퍼를 분리

    int N, M; // 포켓몬의 개수, 문제의 개수
    map<string, int> poketmon;
    map<int, string> num_poketmon;
    cin >> N >> M;
    for (int i = 1; i <= N; i++) {
        string name;
        cin >> name;
        poketmon.insert({ name, i }); // map에 포켓몬 이름과 번호 삽입
        num_poketmon.insert({ i, name }); // map에 번호와 포켓몬 이름 삽입
    }
    for (int i = 0; i < M; i++) {
        string input;
        cin >> input;
        if (i != M - 1) {
            if (isdigit(input[0])) { // 숫자인 경우
                int num = stoi(input); 
                cout << num_poketmon[num] << '\n';
            }
            else { // 문자인 경우
                cout << poketmon[input] << '\n';
            }
        }
        else {
            if (isdigit(input[0])) { // 숫자인 경우
                int num = stoi(input);
                cout << num_poketmon[num];
            }
            else { // 문자인 경우
                cout << poketmon[input];
            }
        }
    }


}