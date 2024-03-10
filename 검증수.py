a = map(int, input().split())
s = 0
for i in a:
    s += i**2
print(s%10)