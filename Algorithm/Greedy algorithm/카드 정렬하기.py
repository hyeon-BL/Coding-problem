import sys
from queue import PriorityQueue

N = int(sys.stdin.readline())
pq = PriorityQueue()

for _ in range(N):
    pq.put(int(sys.stdin.readline()))

min_comparsions = 0
while pq.qsize() != 1:
    first_cards = pq.get()
    second_cards = pq.get()

    comparsions = first_cards + second_cards
    min_comparsions += comparsions
    pq.put(comparsions)

print(min_comparsions)