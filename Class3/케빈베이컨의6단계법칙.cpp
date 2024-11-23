#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int n, m;
vector<int> v[101];
int a, b;
int stepCount = 0; // 시작 사람에서 목표 사람 까지의 단계 수
void bfs(int a,int b, bool visit[101]){
    queue<pair<int, int>> q;
    q.push(make_pair(a,0));
    visit[a] = true;
    while(!q.empty()){
        int x = q.front().first;
        int cnt = q.front().second;
        q.pop();
 
        if(x == b){
            stepCount = cnt;
            break;
        }
 
        for (size_t i = 0; i < v[x].size(); i++){
            if(!visit[v[x][i]]){
                q.push(make_pair(v[x][i], cnt+1));
                visit[v[x][i]] = true;
            }
        }
    }
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);

    int N, M;

    cin >> N >> M;

    for (int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }

    int minDepth = INT_MAX;
    int minNode = 1;
    for (int i = 1; i <= N; i++) { // 모든 노드에 대해 최단 경로(케빈 베이컨)를 구하고, 그 중 최소값을 찾는다.
        int totalDepth = 0;
        for (int j = 1; j <= N; j++) { // i노드를 기준으로 다른 모든 노드에 대해 최단 경로(케빈 베이컨)
            if (i != j) {
                bool visit[101] = {false};
                bfs(i, j, visit);
                totalDepth += stepCount;
                stepCount = 0;
            }
        }
        if (totalDepth < minDepth) {
            minDepth = totalDepth;
            minNode = i;
        }
    }
    cout << minNode;
}