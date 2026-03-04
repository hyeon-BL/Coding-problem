import sys
from queue import PriorityQueue
n, m = map(int, sys.stdin.readline().split())
pq = PriorityQueue()
init = list(map(int, sys.stdin.readline().split()))
for i in range(n):
    pq.put(init[i])
for _ in range(m):
    x = pq.get()
    y = pq.get()
    s = x + y
    pq.put(s)
    pq.put(s)

total = 0
for _ in range(n):
    total += pq.get()
print(total)    