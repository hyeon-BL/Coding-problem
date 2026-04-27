import sys
S = sys.stdin.readline().rstrip()
arr = []
for i in range(len(S)):
	arr.append(S[i:])
arr.sort()
for e in arr:
	print(e)
