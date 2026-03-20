import sys
X = sys.stdin.readline().rstrip()
cnt = 0
while len(X) != 1:
    temp = 0
    for i in range(len(X)):
        temp += int(X[i])
    X = str(temp)
    cnt += 1
print(cnt)
print("NO" if int(X) % 3 else "YES")