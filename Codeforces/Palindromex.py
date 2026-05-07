import sys
T = int(sys.stdin.readline())
for _ in range(T):
	n = int(sys.stdin.readline())
	arr = list(map(int, sys.stdin.readline().split()))

	max_mex = 0
	seen = [False] * (n + 1)
	for c in range(4 * n - 1):
		L = c // 2
		R = (c + 1) // 2

		while L >= 0 and R < 2 * n and arr[L] == arr[R]:
			L -= 1
			R += 1
		L += 1
		R -= 1

		for i in range(L, R + 1):
			seen[arr[i]] = True

		mex = 0
		while mex <= n and seen[mex]:
			mex += 1
		if mex > max_mex:
			max_mex = mex

		for i in range(L, R + 1):
			seen[arr[i]] = False
	print(max_mex)
