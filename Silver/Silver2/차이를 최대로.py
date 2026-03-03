import sys
from itertools import permutations
N = int(sys.stdin.readline())
arr = list(map(int, sys.stdin.readline().split()))
max_val = -1
for permutation in permutations(range(N), N):
    temp = 0
    for idx in range(N - 1):
        temp += abs(arr[permutation[idx]] - arr[permutation[idx + 1]])
    max_val = max(temp, max_val)
print(max_val)