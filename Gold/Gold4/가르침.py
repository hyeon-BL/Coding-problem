import sys
from itertools import combinations

N, K = map(int, sys.stdin.readline().split())
arr = [sys.stdin.readline().strip() for _ in range(N)]

if K < 5:
    print(0)
    sys.exit()

base_letters = set(['a', 'n', 't', 'i', 'c'])
remain = K - 5
if remain >= 21:
    print(N)
    sys.exit()

# map remaining candidate letters to indices 0..20
cands = [chr(ord('a') + i) for i in range(26) if chr(ord('a') + i) not in base_letters]
char_to_idx = {ch: idx for idx, ch in enumerate(cands)}

# precompute word masks (only letters outside 'antic')
word_masks = []
for word in arr:
    m = 0
    for ch in set(word):
        if ch in base_letters:
            continue
        m |= 1 << char_to_idx[ch]
    word_masks.append(m)

# if no extra letters can be taught
if remain == 0:
    print(sum(1 for wm in word_masks if wm == 0))
    sys.exit()

ans = 0
for comb in combinations(range(21), remain):
    mask = 0
    for i in comb:
        mask |= 1 << i
    cnt = 0
    for wm in word_masks:
        # readable if all bits in wm are covered by mask
        if wm & ~mask == 0:
            cnt += 1
    if cnt > ans:
        ans = cnt

print(ans)