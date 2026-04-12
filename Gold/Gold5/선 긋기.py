import sys
N = int(sys.stdin.readline())
arr = [tuple(map(int, sys.stdin.readline().split())) for _ in range(N)]
arr.sort()

res = 0
s = arr[0][0]
e = arr[0][1]

for i in range(1, N):
    if e < arr[i][0]:
        res += e - s
        s = arr[i][0]
        e = arr[i][1]
    else:
        if e < arr[i][1]:
            e = arr[i][1]
res += e - s
print(res)