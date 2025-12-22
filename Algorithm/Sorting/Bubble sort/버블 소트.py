import sys
N = int(sys.stdin.readline())
arr = [(int(sys.stdin.readline()), i) for i in range(N)]

arr.sort()
max_swap = 0
for i in range(N):
    original_index = arr[i][1]
    swap_distance = original_index - i
    if swap_distance > max_swap:
        max_swap = swap_distance
print(max_swap + 1)