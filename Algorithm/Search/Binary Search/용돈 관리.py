import sys
N, M = map(int, sys.stdin.readline().split())
arr = [int(sys.stdin.readline()) for _ in range(N)]

start, end = max(arr), sum(arr)
ans = 0
while start <= end:
    mid = (start + end) // 2
    
    cum, cnt = 0, 1
    for cost in arr:
        if cum + cost <= mid:
            cum += cost
        else:
            cnt += 1
            cum = cost
    
    if cnt > M:
        start = mid + 1
    else:
        end = mid - 1
        ans = mid
print(ans)