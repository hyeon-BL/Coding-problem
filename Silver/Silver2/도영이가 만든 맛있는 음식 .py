import sys
from itertools import combinations
N = int(sys.stdin.readline())
ingredients = [tuple(map(int, sys.stdin.readline().split())) for _ in range(N)]

min_diff = float('inf')
for count in range(1, N + 1):
	for comb in combinations(range(N), count):
		sour = 1
		bitter = 0
		for i in comb:
			sour *= ingredients[i][0]
			bitter += ingredients[i][1]
		min_diff = min(min_diff, abs(sour - bitter))
print(min_diff)
