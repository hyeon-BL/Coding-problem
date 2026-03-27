import sys
N, K = map(int, sys.stdin.readline().split())
nums = [True] * (N + 1)
cnt = 0
for i in range(2, N + 1, 1):
    for j in range(i, N + 1, i):
        if nums[j]:
            nums[j] = False
            cnt += 1
            if cnt == K:
                print(j)
                sys.exit()