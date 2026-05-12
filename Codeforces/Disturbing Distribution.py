import sys
T = int(sys.stdin.readline())
for _ in range(T):
	n = int(sys.stdin.readline())
	arr = list(map(int, sys.stdin.readline().split()))
	res = 0
	cnt_1 = 0
	for i in range(n):
		if arr[i] == 1:
			cnt_1 += 1
		else:
			res = (res + arr[i]) % 676767677
			if cnt_1 > 0:
				cnt_1 = 0
	if cnt_1 > 0:
		res += 1
	print(res)
