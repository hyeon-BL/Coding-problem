#include<iostream>
using namespace std;

void find_room() {
    int H, W, N;
    int level, room;
    int count = 101;

    cin >> H >> W >> N;

    for (int i=1; i<=W; i++) {
        for (int j=1; j<=H; j++) {
            if (N == 1) {
                level = j;
                room = i;
                goto cal;
            }
            N--;
        }
    }
    cal :
        while (count / 100 != level || count % 100 != room) {
            count++;
        }
        cout << count;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);

    int T;
    cin >> T;

    for (int i=0; i<T; i++) {
        find_room();
    }
}