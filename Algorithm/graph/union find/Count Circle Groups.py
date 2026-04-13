import sys
T = int(sys.stdin.readline())

def find(a):
	if parents[a] != a:
		parents[a] = find(parents[a])
	return parents[a]

def union(a, b):
	rootA = find(a)
	rootB = find(b)
	if rootA != rootB:
		parents[rootB] = rootA

def is_group(r1, r2):
	dist = (r1[0] - r2[0]) ** 2 + (r1[1] - r2[1]) ** 2
	if dist <= (r1[2] + r2[2]) ** 2:
		return True
	else:
		return False

for _ in range(T):
	N = int(sys.stdin.readline())
	arr = [tuple(map(int, sys.stdin.readline().split())) for _ in range(N)]
	parents = [i for i in range(N)]
	ans = N

	for i in range(N):
		for j in range(i, N):
			if find(i) != find(j) and is_group(arr[i], arr[j]):
				union(i, j)
				ans -= 1
	print(ans)
