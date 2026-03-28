import sys
N, Q = map(int, sys.stdin.readline().split())
height = 0
length = N

while length:
    length //= 2
    height += 1

size = 2 ** (height + 1)
sIdx = size // 2
tree = [0] * size

tree[sIdx:sIdx + N] = list(map(int, sys.stdin.readline().split()))

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

setTree(size -  1)
for _ in range(Q):
    x, y, a, b = map(int, sys.stdin.readline().split())
    if y < x:
        temp = x
        x = y
        y = temp
    print(getCum(sIdx + x - 1, sIdx + y - 1))
    changeVal(sIdx + a - 1, b)