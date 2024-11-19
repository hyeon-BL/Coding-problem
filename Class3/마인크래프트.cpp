#include<iostream>
using namespace std;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);

    int N, M, B; // N: length(~500), M: width(~500), B: blocks -> 총 256*500*500 = 64000000 (브루트포스 가능)
    cin >> N >> M >> B;

    int** arr = new int* [N];
    for (int i = 0; i < N; i++) {
        arr[i] = new int[M];
    }
    
    for (int i=0; i<N; i++){
        for (int j=0; j<M; j++){
            cin >> arr[i][j];
        }
    }



    int min_time = 1e9, height = 0;
    for (int i=0; i<257; i++) {  // 0~256
        int used = 0, need = 0;
        for (int x=0; x<N; x++) {
            for (int y=0; y<M; y++) {
                int diff = arr[x][y] - i; // 블록을 i로 만들기 위해 필요한 블록 수
                if (diff < 0) {
                    used -= diff; // 블록 더하기
                } else {
                    need += diff; // 블록 빼기
                }
            }
        }

        if (used > B + need) { // 블록이 부족한 경우
            continue;
        }

        int time = 2 * need + used;

        if (time <= min_time) {
            min_time = time;
            height = i;
        }
    }


    cout << min_time << " " << height;
    delete[] arr;
}