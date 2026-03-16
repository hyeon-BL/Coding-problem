import sys
N = int(sys.stdin.readline())
arr = [list(map(int, sys.stdin.readline().split())) for _ in range(N)]
parents = [i for i in range(N + 1)]

def find(a):
    if parents[a] != a:
        parents[a] = find(parents[a])
    return parents[a]

def union(a, b):
    r_a = find(a)
    r_b = find(b)
    if r_a != r_b:
        parents[r_b] = r_a

def CCW(dot1, dot2, dot3):
    res = (dot1[0] * dot2[1] + dot2[0] * dot3[1] + dot3[0] * dot1[1]) \
            - (dot2[0] * dot1[1] + dot3[0] * dot2[1] + dot1[0] * dot3[1])
    if res > 0:
        return 1
    elif res < 0:
        return -1
    return 0

def is_overlapped(dot1, dot2, dot3, dot4):
    if min(dot1[0], dot2[0]) <= max(dot3[0], dot4[0]) and min(dot3[0], dot4[0]) <= max(dot1[0], dot2[0]) \
        and min(dot1[1], dot2[1]) <= max(dot3[1], dot4[1]) and min(dot3[1], dot4[1]) <= max(dot1[1], dot2[1]):
        return 1
    else:
        return 0


def is_crossed(dot1, dot2, dot3, dot4):
    check1 = CCW(dot1, dot2, dot3) * CCW(dot1, dot2, dot4)
    check2 = CCW(dot3, dot4, dot1) * CCW(dot3, dot4, dot2)
    if check1 == 0 and check2 == 0:
        return is_overlapped(dot1, dot2, dot3, dot4)
    elif check1 <= 0 and check2 <= 0:
        return 1
    else:
        return 0
    
for i in range(N - 1):
    for j in range(i + 1, N):
        x1, y1, x2, y2 = arr[i]
        x3, y3, x4, y4 = arr[j]
        if is_crossed((x1, y1), (x2, y2), (x3, y3), (x4, y4)):
            union(i, j)
groups = {}
max_val = 1
for i in range(N):
    root = find(i)
    if root in groups:
        groups[root] += 1
        max_val = max(groups[root], max_val)
    else:
        groups[root] = 1
print(len(groups))
print(max_val)