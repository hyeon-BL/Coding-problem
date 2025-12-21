import sys
n = int(sys.stdin.readline())
A = list(map(int, sys.stdin.readline().split()))
stack = []
result = [-1] * n

for i in range(n):
    while stack and A[stack[-1]] < A[i]:
        result[stack.pop()] = A[i]
    stack.append(i)
print(' '.join(map(str, result)))