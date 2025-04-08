T = int(input())

for i in range(T):
    L=input()
    stack = []
    for i in L:
        if i == '(':
            stack.append(i)
        else:
            if stack:
                stack.pop()
            else:
                print('NO')
                break
    else:
        if stack:
            print('NO')
        else:
            print('YES')