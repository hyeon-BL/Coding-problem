import sys
K = int(sys.stdin.readline())
inOrdered = list(map(int, sys.stdin.readline().split()))
tree = [[] for _ in range(K)]
idx = 0

def restoreTree(i, depth):
    global idx
    if i >= len(inOrdered):
        return
    if depth >= K:
        return
    restoreTree(i * 2 + 1, depth + 1)
    tree[depth].append(inOrdered[idx])
    idx += 1
    restoreTree(i * 2 + 2, depth + 1)

restoreTree(0, 0)
for i in range(K):
    print(" ".join(map(str, tree[i])))