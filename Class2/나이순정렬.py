n = int(input())

a = []
for i in range(n):
    age, name = input().split()
    a.append([int(age), name])

a.sort(key=lambda x: x[0]) # stable sort
for i in a:
    print(i[0], i[1])