import sys
N = int(sys.stdin.readline())
binary_tree = {}
for _ in range(N):
    p, c1, c2 = sys.stdin.readline().split()
    binary_tree[p] = [c1, c2]

def preOrder(cur):
    if cur == '.':
        return
    print(cur, end='')
    preOrder(binary_tree[cur][0])
    preOrder(binary_tree[cur][1])

def inOrder(cur):
    if cur == '.':
        return
    inOrder(binary_tree[cur][0])
    print(cur, end='')
    inOrder(binary_tree[cur][1])

def postOrder(cur):
    if cur == '.':
        return
    postOrder(binary_tree[cur][0])
    postOrder(binary_tree[cur][1])
    print(cur, end='')

preOrder('A')
print()
inOrder('A')
print()
postOrder('A')