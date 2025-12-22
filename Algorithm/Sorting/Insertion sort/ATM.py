import sys
N = int(sys.stdin.readline())
arr = list(map(int, sys.stdin.readline().split()))

for i in range(1, N):
    key = arr[i]
    j = i - 1
    while j >= 0 and arr[j] > key:
        arr[j + 1] = arr[j]
        j -= 1
    arr[j + 1] = key

S = [0] * N
for i in range(N):
    S[i] = S[i - 1] + arr[i]
    
print(sum(S))