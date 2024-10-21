#include <iostream>
#include <algorithm>
using namespace std;

int front_idx = 0; // global front_idx, back_idx
int back_idx = 0;

int my_is_empty() {
    return front_idx == back_idx;
}

void queue_push(int* queue, int x) {
    queue[back_idx++] = x; // back_idx 위치에 x를 넣고 증가
}

int queue_pop(int* queue) {
    if (my_is_empty()) return -1;
    return queue[front_idx++]; // front_idx 위치의 값을 반환하고 증가
}

int queue_size() {
    return back_idx - front_idx;
}

int queue_front(int* queue) {
    if (my_is_empty()) return -1;
    return queue[front_idx];
}

int queue_back(int* queue) {
    if (my_is_empty()) return -1;
    return queue[back_idx - 1];
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);

    int* queue = new int[20001];
    int N;
    cin >> N;
    for (int i = 0; i < N; i++) {
        string s;
        cin >> s;
        if (s == "push") {
            int x;
            cin >> x;
            queue_push(queue, x);
        }
        else if (s == "pop") {
            cout << queue_pop(queue) << '\n';
        }
        else if (s == "size") {
            cout << queue_size() << '\n';
        }
        else if (s == "empty") {
            cout << my_is_empty() << '\n';
        }
        else if (s == "front") {
            cout << queue_front(queue) << '\n';
        }
        else if (s == "back") {
            cout << queue_back(queue) << '\n';
        }
    }

    delete[] queue;
    return 0;
}