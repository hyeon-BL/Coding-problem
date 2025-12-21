import sys
n = int(sys.stdin.readline())
stack = []
operations = []

val = 1
for _ in range(n):
    sequence = int(sys.stdin.readline().strip())
    while val <= sequence:
        stack.append(val)
        operations.append("+")
        val += 1
    if stack[-1] == sequence:
        stack.pop()
        operations.append("-")
    else:
        print("NO")
        sys.exit(0)

for op in operations:
    print(op)