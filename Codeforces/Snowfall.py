import sys
T = int(sys.stdin.readline())
for _ in range(T):
	n = int(sys.stdin.readline())
	arr = list(map(int, sys.stdin.readline().split()))
	d6 = []
	d2 = []
	d3 = []
	other = []
	for i in range(n):
		if arr[i] % 6 == 0:
			d6.append(arr[i])
		elif arr[i] % 2 == 0:
			d2.append(arr[i])
		elif arr[i] % 3 == 0:
			d3.append(arr[i])
		else:
			other.append(arr[i])
	print(*d6, *d2, *other, *d3)
