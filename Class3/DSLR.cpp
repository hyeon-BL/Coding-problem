#include<iostream>
#include<queue>
#include<vector>
using namespace std;


// bfs tree -> shortest path
// do not use multiple elements, use a single element
// this is a difference between dynamic programming and bfs

string bfs(int A, int B) {
    queue<pair<int, string>> q;
    vector<bool> visited(10000, false); // 0 ~ 9999(fixed size to save time)
    q.push({A, ""});
    visited[A] = true;

    while (!q.empty()) {
        int num = q.front().first;
        string ops = q.front().second;
        q.pop();

        if (num == B) return ops;

        // D operation
        int D = (2 * num) % 10000;
        if (!visited[D]) {
            visited[D] = true;
            q.push({D, ops + "D"});
        }

        // S operation
        int S = (num == 0) ? 9999 : num - 1;
        if (!visited[S]) {
            visited[S] = true;
            q.push({S, ops + "S"});
        }

        // L operation
        int L = (num % 1000) * 10 + num / 1000;
        if (!visited[L]) {
            visited[L] = true;
            q.push({L, ops + "L"});
        }

        // R operation
        int R = (num % 10) * 1000 + num / 10;
        if (!visited[R]) {
            visited[R] = true;
            q.push({R, ops + "R"});
        }
    }

    return "";
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);

    int T, A, B;
    cin >> T;
    while(T--) {
        cin >> A >> B;
        cout << bfs(A, B) << '\n';
    }

    return 0;
}