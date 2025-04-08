import re
import sys
n = int(sys.stdin.readline())

stack=[]
for i in range(n):
    S = sys.stdin.readline().rstrip()
    if re.findall(r'push\s[1-9+]', S):
        stack.append(int(S.split()[1]))
    elif S == 'pop':
        if stack:
            print(stack.pop())
        else:
            print(-1)
    elif S == 'size':
        print(len(stack))
    elif S == 'empty':
        print(0 if stack else 1)
    elif S == 'top':
        print(stack[-1] if stack else -1)
