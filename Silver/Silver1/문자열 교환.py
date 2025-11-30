import sys
S = sys.stdin.readline().strip()

total_a = S.count('a')
if total_a <= 1:
    print(0)
    sys.exit()

n = len(S)
S2 = S + S  # Circular string

# initial window
cnt = sum(1 for ch in S2[:total_a] if ch == 'a')
max_a = cnt
for i in range(1, n):
    if S2[i + total_a - 1] == 'a':
        cnt += 1
    if S2[i - 1] == 'a':
        cnt -= 1
    if cnt > max_a:
        max_a = cnt

print(total_a - max_a)

'''
aabbaaabaaba

Explanation:
Total 'a's = 8
We want to group all 'a's together with minimum swaps.

first iteration:
window = aabbaaa b aaba (first 8 chars)
Initial count of 'a's in the first window = 5
max_a = 5

second iteration:
i = 1
window = a bbaaaab aaba (chars 1 to 8)
New char added = 'a' (index 8)
Old char removed = 'a' (index 0)
cnt = 5 + 1 - 1 = 5

third iteration:
i = 2
window = ab baaaaba aba (chars 2 to 9)
New char added = 'a' (index 9)
Old char removed = 'b' (index 1)
cnt = 5 + 1 - 0 = 6

.
.
.
'''