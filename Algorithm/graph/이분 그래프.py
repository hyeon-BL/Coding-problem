import sys
sys.setrecursionlimit(10000)
T = int(sys.stdin.readline())

def dfs(node):
    global is_bipartite
    cur_color = visited[node]
    for next in adj[node]:
        if visited[next] == -1:
            visited[next] = 2 if cur_color == 1 else 1
            dfs(next)
        else:
            if visited[next] == cur_color:
                is_bipartite = False

while T > 0:
    V, E = map(int, sys.stdin.readline().split())
    adj = [[] for _ in range(V + 1)]
    visited = [-1] * (V + 1)
    is_bipartite = True
    for _ in range(E):
        u, v = map(int, sys.stdin.readline().split())
        adj[u].append(v)
        adj[v].append(u)
    
    for i in range(1, V + 1):
        if visited[i] == -1:
            visited[i] = 1
        dfs(i)
        if not is_bipartite:
            break
    if is_bipartite:
        print('YES')
    else:
        print('NO')
    
    T -= 1