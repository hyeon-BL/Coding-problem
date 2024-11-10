#include<iostream>
#include<queue>
using namespace std;

void dfs(int** graph, int* visited, int V, int N) {
    visited[V] = 1;
    cout << V << ' ';
    for (int i = 1; i <= N; i++) { // 인접한 정점들 탐색
        if (graph[V][i] == 1 && visited[i] == 0) {
            dfs(graph, visited, i, N); // 재귀 호출
        }
    }
}

void bfs(int** graph, int* visited, int V, int N) {
    int queue[1001];
    int front = 0, rear = 0;
    queue[rear++] = V;
    visited[V] = 1;
    while (front < rear) { // 큐가 비어있지 않은 동안
        int current = queue[front++];
        cout << current << ' ';
        for (int i = 1; i <= N; i++) { // 인접한 정점들 모두 탐색
            if (graph[current][i] == 1 && visited[i] == 0) {
                queue[rear++] = i;
                visited[i] = 1;
            }
        }
    }
}


int main() {
    int N, M, V;
    cin >> N >> M >> V;
    int** graph = new int*[N + 1];
    for (int i = 0; i <= N; i++) {
        graph[i] = new int[N + 1];
        fill(graph[i], graph[i] + N + 1, 0); // 0으로 초기화
    }
    for (int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;
        graph[a][b] = 1; // a에서 b로 가는 간선이 있다
        graph[b][a] = 1; // b에서 a로 가는 간선이 있다
    }
    int* visited = new int[N + 1];
    fill(visited, visited + N + 1, 0); // 0으로 초기화
    dfs(graph, visited, V, N);
    cout << '\n';
    fill(visited, visited + N + 1, 0); // 0으로 초기화
    bfs(graph, visited, V, N);
}