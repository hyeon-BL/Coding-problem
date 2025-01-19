#include <iostream>
#include <string>
#include <vector>
using namespace std;

enum class isreturn
{
    YES,
    NO,
    UNKNOWN
};

struct student
{
    int num;
    string name;
    isreturn isret;

    student() : num(0), name(""), isret(isreturn::UNKNOWN) {}
};

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    int N, sn, cnt = 1;
    string AB;
    while (true)
    {
        cin >> N;
        if (N == 0)
        {
            break;
        }
        vector<student> students(N);
        cin.ignore();
        for (int i = 0; i < N; i++)
        {
            getline(cin, students[i].name);
        }
        for (int i = 0; i < 2 * N - 1; i++)
        {
            cin >> sn >> AB;
            students[sn - 1].num = sn;
            if (students[sn - 1].isret == isreturn::UNKNOWN)
            {
                students[sn - 1].isret = isreturn::NO;
            }
            else
            {
                students[sn - 1].isret = isreturn::YES;
            }
        }
        for (int i = 0; i < N; i++)
        {
            if (students[i].isret == isreturn::NO)
            {
                cout << cnt << ' ' << students[i].name << '\n';
            }
        }
        cnt++;
    }
}