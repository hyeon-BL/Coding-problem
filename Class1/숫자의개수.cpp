#include<iostream>
#include<string>
using namespace std;

int main() {
    int A, B, C;
    int mul, temp;

    cin >> A >> B >> C;
    mul = A * B * C;
    string val = to_string(mul);
    int arr[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

    for (int i=0; i<10; i++) {
        temp = int(val[i]) - 48; // val[i]는 char형이므로 48을 빼주어 int형으로 변환
        arr[temp] += 1;
    }

    for (int i=0; i<10; i++) {
        cout << arr[i] << endl;
    }
}