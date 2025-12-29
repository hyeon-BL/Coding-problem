import sys
N = int(sys.stdin.readline())
K = int(sys.stdin.readline())
start = 1
end = K
ans = -1

while start <= end:
    mid = (start + end) // 2
    cnt = 0

    for i in range(1, N + 1):
        cnt += min(N, mid // i)
    
    if cnt < K:
        start = mid + 1
    else:
        end = mid - 1
        ans = mid

print(ans)