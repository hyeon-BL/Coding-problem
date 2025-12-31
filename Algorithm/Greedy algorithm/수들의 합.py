import sys
S = int(sys.stdin.readline())
max_N = 0
for i in range(100000):
    if i * (i + 1) / 2 > S:
        max_N = i - 1
        break
print(max_N)