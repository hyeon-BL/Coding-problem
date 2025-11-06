import sys
N = int(sys.stdin.readline())
words = [sys.stdin.readline().strip() for _ in range(N)]

similar = 0
for i in range(N):
    for j in range(i + 1, N):
        temp = {}
        for a, b in zip(words[i], words[j]):
            if a in temp and temp[a] != b:
                break
            if b in temp.values() and a not in temp:
                break
            temp[a] = b
        else:
            similar += 1
print(similar)