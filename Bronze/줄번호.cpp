#include <iostream>
#include <string>
using namespace std;

int main()
{
    int N;
    string line;
    cin >> N;
    cin.ignore(); // cin으로 입력받은 후에 getline을 사용할 때 버퍼에 남아있는 개행문자를 제거
    for (int i = 1; i <= N; i++)
    {
        getline(cin, line);
        cout << i << ". " << line << '\n';
    }
    return 0;
}