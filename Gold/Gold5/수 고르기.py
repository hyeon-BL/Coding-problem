import sys
N, M = map(int, sys.stdin.readline().split())
arr = [int(sys.stdin.readline()) for _ in range(N)]
arr.sort()

start = 0
end = 1
diff = float('inf')
while start < N and end < N:
	cur_diff = arr[end] - arr[start]
	if cur_diff > M:
		diff = min(diff, cur_diff)
		start += 1
	elif cur_diff == M:
		diff = cur_diff
		break
	else:
		end += 1
print(diff)
