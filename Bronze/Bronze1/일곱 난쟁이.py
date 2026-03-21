import sys
from itertools import combinations
dwarfs = [int(sys.stdin.readline()) for _ in range(9)]
dwarfs.sort()
for comb in combinations(range(9), 7):
    s = 0
    for idx in comb:
        s += dwarfs[idx]
    if s == 100:
        break
for idx in comb:
    print(dwarfs[idx])