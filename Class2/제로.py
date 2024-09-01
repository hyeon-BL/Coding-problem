n = int(input())
a = []
for i in range(n):
    inp = int(input())
    if inp == 0:
        a.pop()
    else:
        a.append(inp)
print(sum(a))