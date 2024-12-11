import sys
from collections import deque

N, M = map(int, sys.stdin.readline().split())
grid = [list(sys.stdin.readline().strip()) for _ in range(N)]

# Create vertex splitting graph
# Each cell (i,j) becomes two vertices: 2*(i*M + j) and 2*(i*M + j) + 1
def get_in_vertex(i, j):
    return 2 * (i * M + j)

def get_out_vertex(i, j):
    return 2 * (i * M + j) + 1

# Find K and H positions
start = end = None
for i in range(N):
    for j in range(M):
        if grid[i][j] == 'K':
            start = get_out_vertex(i, j)
        elif grid[i][j] == 'H':
            end = get_in_vertex(i, j)

# Create graph with vertex splitting
graph = {i: [] for i in range(2 * N * M)}
directions = [(0, 1), (1, 0), (0, -1), (-1, 0)]
INF = float('inf')

for i in range(N):
    for j in range(M):
        if grid[i][j] != '#':
            # Connect split vertices with capacity 1
            in_v = get_in_vertex(i, j)
            out_v = get_out_vertex(i, j)
            if grid[i][j] not in ['K', 'H']:
                graph[in_v].append((out_v, 1))
                graph[out_v].append((in_v, 0))  # reverse edge

            # Connect to adjacent cells with infinite capacity
            for di, dj in directions:
                ni, nj = i + di, j + dj
                if 0 <= ni < N and 0 <= nj < M and grid[ni][nj] != '#':
                    graph[out_v].append((get_in_vertex(ni, nj), INF))
                    graph[get_in_vertex(ni, nj)].append((out_v, 0))  # reverse edge

def bfs(graph, flow, source, sink, parent): 
    visited = [False] * len(graph)
    visited[source] = True
    queue = [source]
    
    while queue:
        u = queue.pop(0)
        for v, w in graph[u]:
            if not visited[v] and w > flow.get((u, v), 0):
                visited[v] = True
                parent[v] = u
                queue.append(v)
                if v == sink:
                    return True
    return False

def ford_fulkerson(graph, source, sink):
    flow = {}
    parent = [-1] * len(graph)
    max_flow = 0
    
    while bfs(graph, flow, source, sink, parent):
        path_flow = float('inf')
        v = sink
        
        while v != source:
            u = parent[v]
            for dest, weight in graph[u]:
                if dest == v:
                    path_flow = min(path_flow, weight - flow.get((u, v), 0))
                    break
            v = parent[v]
            
        if path_flow == 0:
            break
            
        max_flow += path_flow
        v = sink
        
        while v != source:
            u = parent[v]
            flow[(u, v)] = flow.get((u, v), 0) + path_flow
            flow[(v, u)] = flow.get((v, u), 0) - path_flow
            v = parent[v]
    
    return max_flow if max_flow < float('inf') else -1

result = ford_fulkerson(graph, start, end)
print(result)


"""
5 4
#...
#.#.
K..H
.#.#
...#

"""