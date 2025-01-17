K = int(input())
password = input()

arr = [[] * K for _ in range(len(password) // K)]
for i in range(len(password) // K):
    if i % 2 == 1:
        arr[i] = list(password[i * K:(i + 1) * K])[::-1]
    else:
        arr[i] = list(password[i * K:(i + 1) * K])

for i in range(K):
    for j in range(len(password) // K):
        print(arr[j][i], end="")    