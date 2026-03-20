import sys
S = sys.stdin.readline().rstrip()
res = []
stack = []
i = 0
while i < len(S):
    c = S[i]
    if c == '<':
        while stack:
            res.append(stack.pop())
        while i < len(S) and S[i] != '>':
            res.append(S[i])
            i += 1
        if i < len(S):
            res.append(S[i])
            i += 1
    elif c == ' ':
        while stack:
            res.append(stack.pop())
        res.append(' ')
        i += 1
    else:
        stack.append(c)
        i += 1

while stack:
    res.append(stack.pop())

print(''.join(res))