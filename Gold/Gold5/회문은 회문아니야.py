import sys
S = sys.stdin.readline().rstrip()
leng = len(S)
is_palin = True
is_all_equal = True
for i in range(leng // 2):
    if S[i] != S[leng - i - 1]:
        is_palin = False
        break
for i in range(leng):
    if S[i] != S[0]:
        is_all_equal = False
        break

if is_all_equal:
    print(-1)
elif is_palin:
    print(leng - 1)
else:
    print(leng)