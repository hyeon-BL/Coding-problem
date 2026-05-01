from collections import deque

def solution(m, n, h, w, drops):
    answer = []    
    grid = [[float('inf')] * n for _ in range(m)]
    for idx, (r, c) in enumerate(drops, 1):
        grid[r][c] = idx
    
    def min_window(arr, k):
        res = []
        dq = deque()
        for i in range(len(arr)):
            if dq and dq[0] <= i - k:
                dq.popleft()
            while dq and arr[dq[-1]] >= arr[i]:
                dq.pop()
            dq.append(i)
            if i >= k - 1:
                res.append(arr[dq[0]])
        return res

    row_mins = []
    for r in range(m):
        row_mins.append(min_window(grid[r], w))

    final_m, final_n = m - h + 1, n - w + 1
    best_pick = (-1, -float('inf'), -float('inf'))
    answer = [0, 0]

    for j in range(final_n):
        col_row = [row_mins[i][j] for i in range(m)]
        col_row_mins = min_window(col_row, h)
        
        for i, current_min in enumerate(col_row_mins):
            current_state = (current_min, -i, -j)
            
            if current_state > best_pick:
                best_pick = current_state
                answer = [i, j]

    return answer

ans = solution(3, 3, 1, 1, [[0, 0], [0, 1], [0, 2], [1, 0]])
print(ans)