import sys
T = int(sys.stdin.readline())
for _ in range(T):
	n = int(sys.stdin.readline())
	arr = list(map(int, sys.stdin.readline().split()))
	shift = sorted(arr)

	original = 0
	for i in range(n):
		original += arr[i] * (i + 1)
	final = 0
	for i in range(n):
		final += shift[i] * (i + 1)
	base = final - original

	first_occ = {}
	for i in range(n):
		val = shift[i]
		if val not in first_occ:
			first_occ[val] = i + 1

	max_gain = 0
	for i in range(n):
		val = arr[i]
		k = first_occ[val]
		gain = (i + 1) - k
		max_gain = max(max_gain, gain)

	print(base + max_gain)
