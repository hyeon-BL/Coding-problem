import sys
N = int(sys.stdin.readline())
strows = []
for _ in range(N):
    strows.append(int(sys.stdin.readline()))
strows.sort(reverse=True)

for i in range(len(strows) - 2):
    if strows[i] < strows[i + 1] + strows[i + 2]:
        print(strows[i] + strows[i + 1] + strows[i + 2])
        break
else:
    print(-1)