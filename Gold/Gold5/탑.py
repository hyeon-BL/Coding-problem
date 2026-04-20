import sys
N = int(sys.stdin.readline())
arr = list(map(int, sys.stdin.readline().split()))

res = [0] * N
stack = []

for i, h in enumerate(arr, start=1):
	while stack and stack[-1][0] < h:
		stack.pop()
	res[i - 1] = stack[-1][1] if stack else 0
	stack.append((h, i))

print(*res)
