#include <iostream>
using namespace std;

int gcd(int a, int b)
{
    int gcd;
    int temp_a = a;
    int temp_b = b;
    while (temp_b != 0)
    {
        gcd = temp_b;
        temp_b = temp_a % temp_b;
        temp_a = gcd;
    }
    return gcd; // 최대공약수 계산
}

int lcm(int a, int b)
{
    int gcd_value = gcd(a, b);
    return (a / gcd_value) * b; // 최소공배수 계산
}

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    int A1, B1, A2, B2;
    cin >> A1 >> B1 >> A2 >> B2;

    int denominator = lcm(B1, B2);
    int numerator = (A1 * (denominator / B1)) + (A2 * (denominator / B2));

    int reduced = gcd(numerator, denominator);
    numerator /= reduced;
    denominator /= reduced;

    cout << numerator << ' ' << denominator << '\n';
    return 0;
}