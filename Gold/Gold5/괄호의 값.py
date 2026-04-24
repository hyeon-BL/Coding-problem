import sys
brackets = sys.stdin.readline().rstrip()
score = 0
temp = 1
flag = 0
stack = []
for i in range(len(brackets)):
    if brackets[i] == '(' or brackets[i] == '[':
        temp *= 2 if brackets[i] == '(' else 3
        stack.append('(' if brackets[i] == '(' else '[')
        flag = 1
    elif len(stack) != 0 and stack[-1] == '(' and brackets[i] == ')':
        stack.pop()
        if flag:
            score += temp
        temp //= 2
        flag = 0
    elif len(stack) != 0 and stack[-1] == '[' and brackets[i] == ']':
        stack.pop()
        if flag:
            score += temp
        temp //= 3
        flag = 0
    else:
        print(0)
        break
else:
    if len(stack) != 0:
        print(0)
    else:
        print(score)