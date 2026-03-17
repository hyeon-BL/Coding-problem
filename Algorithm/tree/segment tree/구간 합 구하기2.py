import sys
N, M, K = map(int, sys.stdin.readline().split())
tree1 = [0] * (N + 2) # diff 누적
tree2 = [0] * (N + 2) # diff * (i - 1) 누적

def update(tree, i, diff):
    while i <= N:
        tree[i] += diff
        i += (i & -i)

def query(tree, i):
    ans = 0
    while i > 0:
        ans += tree[i]
        i -= (i & -i)
    return ans

def plusVal(s, e, val): # Difference array 성질 이용 -> 경계값에만 val 업데이트
    update(tree1, s, val)
    update(tree1, e + 1, -val)
    update(tree2, s, val * (s - 1))
    update(tree2, e + 1, -val * e)

def getPrefixSum(idx):
    return query(tree1, idx) * idx - query(tree2, idx)

def getCum(start, end):
    return getPrefixSum(end) - getPrefixSum(start - 1)

for i in range(1, N + 1):
    num = int(sys.stdin.readline())
    plusVal(i, i, num)

for _ in range(M + K):
    a, *ans = map(int, sys.stdin.readline().split())
    if a == 1:
        plusVal(ans[0], ans[1], ans[2])
    elif a == 2:
        cumulativeSum = getCum(ans[0], ans[1])
        print(cumulativeSum)