import sys
N = int(sys.stdin.readline())
arr = [tuple(map(int, sys.stdin.readline().split())) for _ in range(N)]
arr.append((arr[0][0], arr[0][1]))

res = 0
for i in range(N):
    res += (arr[i][0] * arr[i + 1][1]) - (arr[i + 1][0] * arr[i][1])
print(round(abs(res/2), 1))