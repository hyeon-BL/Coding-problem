N, M = map(int, input().split())
board = [input().strip() for _ in range(N)]
visited = [[False] * M for _ in range(N)]

count = 0
for i in range(N):
    for j in range(M):
        if board[i][j] == '-' and not visited[i][j]:
            count += 1
            for k in range(j, M):
                if board[i][k] == '-':
                    visited[i][k] = True
                else:
                    break
        elif board[i][j] == '|' and not visited[i][j]:
            count += 1
            for k in range(i, N):
                if board[k][j] == '|':
                    visited[k][j] = True
                else:
                    break
print(count)