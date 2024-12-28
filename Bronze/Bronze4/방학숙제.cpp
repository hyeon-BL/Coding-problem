#include <iostream>
using namespace std;

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    int L, A, B, C, D;
    cin >> L >> A >> B >> C >> D;

    int korean = (A % C == 0) ? A / C : A / C + 1;
    int math = (B % D == 0) ? B / D : B / D + 1;

    cout << L - max(korean, math);
}