import sys
N, M = map(int, sys.stdin.readline().split())
arr = list(map(int, sys.stdin.readline().split()))
arr.sort()

def backtrack(start, nums):
	global M

	if (len(nums) == M):
		print(' '.join(map(str, nums)))
		return

	for i in range(start, N):
		nums.append(arr[i])
		backtrack(i, nums)
		nums.pop()

backtrack(0, [])
