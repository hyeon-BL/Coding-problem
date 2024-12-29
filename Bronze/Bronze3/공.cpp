#include <iostream>
using namespace std;

struct cup
{
    bool hasBall;

    // Copy constructor
    cup(const cup &other)
    {
        hasBall = other.hasBall;
    }

    // Default constructor
    cup() : hasBall(false) {}
};

void swap(cup &a, cup &b)
{
    cup temp = a;
    a = b;
    b = temp;
};

int main()
{
    cup cups[4];
    cups[1].hasBall = true;
    int N;
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        int a, b;
        cin >> a >> b;
        swap(cups[a], cups[b]);
    }
    for (int i = 1; i <= 3; i++)
    {
        if (cups[i].hasBall)
        {
            cout << i;
            return 0;
        }
    }
    cout << -1;
    return 0;
}