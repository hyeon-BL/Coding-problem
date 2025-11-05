import sys

# Read 28 integers (percentages) from input representing the upper triangle of the 8×8 matrix
tokens = list(map(int, sys.stdin.readline().split()))
p = [[0.0] * 8 for _ in range(8)]
idx = 0
for i in range(8):
	for j in range(i + 1, 8):
		v = tokens[idx] / 100.0
		p[i][j] = v
		p[j][i] = 1.0 - v
		idx += 1

sys.setrecursionlimit(10000)

def solve(l, r):
	# base case: single player at position l..r where l==r
	if l == r:
		arr = [0.0] * 8
		arr[l] = 1.0
		return arr
	mid = (l + r) // 2
	left = solve(l, mid)
	right = solve(mid + 1, r)
	res = [0.0] * 8
	# players from left subtree
	for i in range(l, mid + 1):
		s = 0.0
		for j in range(mid + 1, r + 1):
			s += right[j] * p[i][j]
		res[i] = left[i] * s
	# players from right subtree
	for i in range(mid + 1, r + 1):
		s = 0.0
		for j in range(l, mid + 1):
			s += left[j] * p[i][j]
		res[i] = right[i] * s
	return res

# Compute probabilities for full interval [0..7] and print
res = solve(0, 7)
for prob in res:
	print("{:.10f}".format(prob), end=' ')

