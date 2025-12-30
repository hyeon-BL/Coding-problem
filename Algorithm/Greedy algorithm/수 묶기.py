import sys
from queue import PriorityQueue

N = int(sys.stdin.readline())
Plus_pq = PriorityQueue()
Minus_pq = PriorityQueue()
zeros = 0

for _ in range(N):
    num = int(sys.stdin.readline())
    if num > 0:
        Plus_pq.put(-1 * num) # 절댓값 내림차순
    elif num < 0:
        Minus_pq.put(num) # 절댓값 내림차순
    else:
        zeros += 1

max_sum = 0
while Plus_pq.qsize() > 1:
    fst = Plus_pq.get()
    snd = Plus_pq.get()
    if fst == -1 or snd == -1:
        max_sum += fst * -1
        max_sum += snd * -1
    else:
        max_sum += fst * snd
if Plus_pq.qsize() == 1:
    max_sum += Plus_pq.get() * -1

while Minus_pq.qsize() > 1:
    fst = Minus_pq.get()
    snd = Minus_pq.get()
    max_sum += fst * snd
if Minus_pq.qsize() == 1:
    if not zeros:
        max_sum += Minus_pq.get()

print(max_sum)