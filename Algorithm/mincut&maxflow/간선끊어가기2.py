import sys

N, M = map(int, sys.stdin.readline().split()) # N : 정점 수, M : 간선 수

# adjacency list
graph = {i: [] for i in range(0, N)} # 0: A거점, n-1: B거점

# 그래프 생성
for _ in range(M):
    a, b, w = map(int, sys.stdin.readline().split())
    a -= 1
    b -= 1
    graph[a].append((b, w))  # (destination, weight)
    graph[b].append((a, w))  # undirected graph

s, t = map(int, sys.stdin.readline().split())
s -= 1
t -= 1

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
    
    # Find max flow
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
            
        max_flow += path_flow
        v = sink
        
        while v != source:
            u = parent[v]
            flow[(u, v)] = flow.get((u, v), 0) + path_flow
            flow[(v, u)] = flow.get((v, u), 0) - path_flow
            v = parent[v]
    
    # Find min cut using BFS from source
    visited = set()
    queue = [source]
    visited.add(source)
    
    while queue:
        if sink in visited:
            break

        u = queue.pop(0)
        for v, w in graph[u]:
            # Only visit nodes that have remaining capacity
            if v not in visited and w > flow.get((u, v), 0):
                visited.add(v)
                queue.append(v)
    
    # Calculate min cut value by summing saturated edges
    min_cut = 0
    for u in visited:
        for v, w in graph[u]:
            if v not in visited:
                min_cut += flow.get((u, v), 0)  # Count actual flow through cut edges
    
    return min_cut if sink not in visited else -1

result = ford_fulkerson(graph, s, t)
print(result)