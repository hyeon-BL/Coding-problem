import sys
N, d, k, c = map(int, sys.stdin.readline().split())
sushis = [int(sys.stdin.readline()) for _ in range(N)]
sushis = sushis + sushis # for circularity

max_cnt = -1
end = k
for start in range(N):
    comb = set() # for uniqueness
    for i in range(start, end):
        comb.add(sushis[i])
    
    cnt = len(comb)
    if c not in comb:
        cnt += 1
    max_cnt = max(max_cnt, cnt)

    end += 1

print(max_cnt)
