import sys
N, M, K = map(int, sys.stdin.readline().split())
height = 0
length = N

while length:
    length //= 2
    height += 1

size = 2 ** (height + 1)
startIdx = size // 2
tree = [0] * size

for i in range(startIdx, startIdx + N):
    tree[i] = int(sys.stdin.readline())

def setTree(i):
    while i != 1:
        tree[i // 2] += tree[i]
        i -= 1

def changeVal(idx, val):
    diff = tree[idx] - val
    while idx:
        tree[idx] -= diff
        idx //= 2

def getCum(start, end):
    cum = 0
    while start <= end:
        if start % 2 == 1:
            cum += tree[start]
            start += 1
        if end % 2 == 0:
            cum += tree[end]
            end -= 1
        start //= 2
        end //= 2
    return cum

setTree(size - 1)
for _ in range(M + K):
    a, b, c = map(int, sys.stdin.readline().split())
    if a == 1:
        changeVal(startIdx + b - 1, c)
    elif a == 2:
        cumulativeSum = getCum(startIdx + b - 1, startIdx + c - 1)
        print(cumulativeSum)