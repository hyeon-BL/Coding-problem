import sys
import itertools
A, B = map(int, sys.stdin.readline().split())

count = 0
for num_len in range(1, 10):
    for comb in itertools.product([4, 7], repeat=num_len):
        val = 0
        for d in comb:
            val = val * 10 + d
        if A <= val <= B:
            count += 1
print(count)