import sys

N = int(sys.stdin.readline())
prices = [list(map(int, sys.stdin.readline().strip())) for _ in range(N)]

dp = [[float('inf')] * N for _ in range(1 << N)]
dp[1 << 0][0] = 0  # artist 1 starts with purchase price 0

for mask in range(1 << N):
    for j in range(N):
        last_price = dp[mask][j]
        if last_price == float('inf'):
            continue
        for k in range(N):  
            if mask & (1 << k):
                continue
            sale_price = prices[j][k] # price at which artist j sells to artist k
            if sale_price >= last_price:
                next_mask = mask | (1 << k)
                if sale_price < dp[next_mask][k]:
                    dp[next_mask][k] = sale_price

ans = 0
for mask in range(1 << N):
    for j in range(N):
        if dp[mask][j] != float('inf'):
            cnt = mask.bit_count()  # number of owners so far
            if cnt > ans:
                ans = cnt

print(ans)

