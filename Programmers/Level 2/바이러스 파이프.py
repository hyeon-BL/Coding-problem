from itertools import product

def solution(n, infection, edges, k):
    answer = 0
    
    for p in product(range(1, 4), repeat=k):
        cnt = 1
        order = 0

        visited = [False] * (n + 1)
        visited[infection] = True
        def dfs(cur, order):
            nonlocal cnt
            visited[cur] = True
            for edge in edges:
                if cur not in edge[:2]:
                    continue
                nxt = edge[0] if edge[1] == cur else edge[1]
                if edge[2] == p[order] and not visited[nxt]:
                    dfs(nxt, order)
                    cnt += 1
        while order < k:
            for i in range(1, n + 1):
                if visited[i]:
                    dfs(i, order)
            order += 1
        answer = max(answer, cnt)
    return answer

n = 7
infection = 6
edges = [[1, 2, 3], [1, 4, 3], [4, 5, 1], [5, 6, 1], [3, 6, 2], [3, 7, 2]]
k = 3

print(solution(n, infection, edges, k))