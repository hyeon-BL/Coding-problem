import sys

def choose(cnt, start):
	global N, nums, visited

	if (cnt == 6):
		for i in range(N):
			if visited[i]:
				print(nums[i], end=' ')
		print()
		return

	for i in range(start, N):
		if not visited[i]:
			visited[i] = True
			choose(cnt + 1, i + 1)
			visited[i] = False

while True:
	case = list(map(int, sys.stdin.readline().split()))
	N = case[0]
	nums = case[1:]
	visited = [False] * N
	if N == 0:
		break
	choose(0, 0)
	print()
