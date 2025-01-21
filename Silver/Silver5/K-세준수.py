N = int(input())
K = int(input())

cnt = 0

arr = [0] * (N+1)
for i in range(2, N+1):
    if arr[i] == 0:
        for j in range(i, N+1, i):
            try:
                arr[j] = max(arr[j], i)
            except:
                pass

for i in range(1, N+1):
    if arr[i] <= K:
        cnt += 1

print(cnt)