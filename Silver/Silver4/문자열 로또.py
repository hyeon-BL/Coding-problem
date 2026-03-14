import sys
L, N = map(int, sys.stdin.readline().split())
arr = [sys.stdin.readline().rstrip() for _ in range(N)]
K = int(sys.stdin.readline())

sub_s = {}
for s in arr:
    for i in range(L - K + 1):
        sub = s[i : i + K]
        if sub in sub_s:
            sub_s[sub] += 1
        else:
            sub_s[sub] = 1
print(max(sub_s.values()))