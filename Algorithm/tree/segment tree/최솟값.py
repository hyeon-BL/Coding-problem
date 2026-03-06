import sys
N, M = map(int, sys.stdin.readline().split())
height = 0
length = N

while length:
    length //= 2
    height += 1

size = 2 ** (height + 1)
startIdx = size // 2
tree = [float('inf')] * size

for i in range(startIdx, startIdx + N):
    tree[i] = int(sys.stdin.readline())

def setTree(i):
    while i != 1:
        tree[i // 2] = min(tree[i // 2], tree[i])
        i -= 1

def getMin(start, end):
    minVal = float('inf')
    while start <= end:
        if start % 2 == 1:
            minVal = min(minVal, tree[start])
            start += 1
        if end % 2 == 0:
            minVal = min(minVal, tree[end])
            end -= 1
        start //= 2
        end //= 2
    return minVal

setTree(size - 1)
for _ in range(M):
    a, b = map(int, sys.stdin.readline().split())
    aIdx = startIdx + a - 1
    bIdx = startIdx + b - 1
    print(getMin(aIdx, bIdx))
