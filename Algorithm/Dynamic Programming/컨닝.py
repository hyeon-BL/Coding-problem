import sys
C = int(sys.stdin.readline())

def count_bits(mask):
    cnt = 0
    while mask:
            mask &= (mask - 1)
            cnt += 1
    return cnt

for _ in range(C):
    N, M = map(int, sys.stdin.readline().split())
    grid = [0] * N
    for i in range(N):
        row = sys.stdin.readline().rstrip()
        for j in range(M):
            if row[j] == 'x':
                grid[i] |= (1 << j)

    dp = [[-1] * (1 << M) for _ in range(N)]
    for i in range(N):
        for possible in range(0, (1 << M)):
            if possible & grid[i] != 0:
                continue
            if possible & (possible << 1) != 0:
                continue
            if i == 0:
                dp[i][possible] = count_bits(possible)
            else:
                for prev in range(1 << M):
                    if dp[i - 1][prev] == -1:
                        continue
                    # possible & (prev << 1): 윗 줄의 왼쪽 대각선 자리에 사람이 있는지 확인
                    # possible & (prev >> 1): 윗 줄의 오른쪽 대각선 자리에 사람이 있는지 확인
                    if (possible & (prev << 1)) == 0 and (possible & (prev >> 1)) == 0:
                        dp[i][possible] = max(dp[i][possible], dp[i - 1][prev] + count_bits(possible))

    print(max(dp[N - 1]))
            