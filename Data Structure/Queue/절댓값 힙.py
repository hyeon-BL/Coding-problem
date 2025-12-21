import sys
from queue import PriorityQueue

N = int(sys.stdin.readline())
pq = PriorityQueue()

for _ in range(N):
    num = int(sys.stdin.readline())
    if num == 0:
        if pq.empty():
            print(0)
        else:
            print(pq.get()[1])
    else:
        pq.put((abs(num), num))