import sys
N, M = map(int, sys.stdin.readline().split())
arr = list(map(int, sys.stdin.readline().split()))
arr.sort()

def backtrack(nums):
	global M

	if (len(nums) == M):
		print(" ".join(map(str, nums)))
		return

	for ele in arr:
		nums.append(ele)
		backtrack(nums)
		nums.pop()

backtrack([])
