#include<iostream>
using namespace std;

int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int A, B, N;
    cin >> A >> B >> N;

    A = A % B; // Get the remainder of A divided by B
    for (int i = 0; i < N - 1; ++i) {
        A = (A * 10) % B; // Move to the next digit
    }
    int nth_digit = (A * 10) / B; // Get the Nth digit
    cout << nth_digit << endl;

    return 0;
}