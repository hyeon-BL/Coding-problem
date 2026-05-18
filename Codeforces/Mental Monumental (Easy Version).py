import sys
T = int(sys.stdin.readline())

def check(m):
	needed = [True] * m
	leftovers = []
	# Phase 1: Exact Match
	for x in arr:
		if x < m and needed[x]:
			needed[x] = False
		else:
			leftovers.append(x)
	unmatched = [i for i in range(m) if needed[i]]

	# Phase 2: Flexible Match (투 포인터)
	ptr = 0
	for t in unmatched:
		req = 2 * t + 1
		while ptr < len(leftovers) and leftovers[ptr] < req:
			ptr += 1
		if ptr == len(leftovers):
			return False
		ptr += 1
	return True


for _ in range(T):
	N = int(sys.stdin.readline())
	arr = list(map(int, sys.stdin.readline().split()))
	arr.sort()

	# Parametric Search를 통한 최적해 도출
	left, right = 0, N
	ans = 0

	while left <= right:
		mid = (left + right) // 2
		if check(mid):
			ans = mid
			left = mid + 1
		else:
			right = mid - 1
	print(ans)
