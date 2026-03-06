import sys
N, M, K = map(int, sys.stdin.readline().split())
height = 0
length = N
MOD = 1000000007

while length:
    length //= 2
    height += 1

size = 2 ** (height + 1)
startIdx = size // 2
tree = [1] * size

for i in range(startIdx, startIdx + N):
    tree[i] = int(sys.stdin.readline())

def setTree(i):
    while i != 1:
        tree[i // 2] *= tree[i]
        tree[i // 2] %= MOD
        i -= 1

def changeVal(idx, val):
    tree[idx] = val
    while idx:
        idx //= 2
        tree[idx] = (tree[idx * 2] % MOD) * (tree[idx * 2 + 1] % MOD)

def getCum(start, end):
    cum = 1
    while start <= end:
        if start % 2 == 1:
            cum *= tree[start]
            cum %= MOD
            start += 1
        if end % 2 == 0:
            cum *= tree[end]
            cum %= MOD
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
        cumulativeMul = getCum(startIdx + b - 1, startIdx + c - 1)
        print(cumulativeMul)