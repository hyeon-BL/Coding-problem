import sys
N, X = map(int, sys.stdin.readline().split())
days = list(map(int, sys.stdin.readline().split()))
culDays = [days[0]] * N
for i in range(1, N):
    culDays[i] = culDays[i - 1] + days[i]

start = 0
end = X - 1
maxVal = -1
cnt = 0
while end < N:
    S = culDays[end] - culDays[start] + days[start]
    if maxVal < S:
        maxVal = S
        cnt = 1
    elif maxVal == S:
        cnt += 1
    start += 1
    end += 1

if maxVal == 0:
    print("SAD")
else:
    print(maxVal)
    print(cnt)