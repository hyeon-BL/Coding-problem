arr = []
N = int(input())

for i in range(N):
    arr.append(int(input()))

cnt = 0
dasom = arr.pop(0)

if N == 1:
    print(0)
    exit()

for i in range(N):
    while dasom <= max(arr):
        cnt += 1
        arr[arr.index(max(arr))] -= 1
        dasom += 1
    else:
        break

print(cnt)