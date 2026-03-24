import sys
w, h = map(int, sys.stdin.readline().split())
p, q = map(int, sys.stdin.readline().split())
t = int(sys.stdin.readline())

pd, pm = divmod(t + p, w)
qd, qm = divmod(t + q, h)
if pd % 2 == 1:
    pm = w - pm
if qd % 2 == 1:
    qm = h - qm
print(pm, qm)