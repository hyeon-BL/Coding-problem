import sys
from itertools import permutations
N = int(sys.stdin.readline())
for arr in permutations(range(1, N + 1), N):
	print(*arr)




arr = [i for i in range(1, N + 1)]

def backtrack(nums):
	global N

	if (len(nums) == N):
		print(' '.join(map(str, nums)))
		return

	for i in range(N):
		if arr[i] not in nums:
			nums.append(arr[i])
			backtrack(nums)
			nums.pop()

backtrack([])
