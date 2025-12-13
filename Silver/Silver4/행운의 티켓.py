import sys
S = sys.stdin.readline().rstrip()
length = len(S)
culmulative_sum = [0] * (length + 1)
for i in range(1, length + 1):
    culmulative_sum[i] = culmulative_sum[i - 1] + int(S[i - 1])

result = 0
if length == 1:
    print(0)
else:
    for len_sub in range(2, length + 1, 2):
        for start in range(0, length - len_sub + 1):
            end = start + len_sub
            mid = (start + end) // 2
            if culmulative_sum[mid] - culmulative_sum[start] == culmulative_sum[end] - culmulative_sum[mid]:
                result = max(result, len_sub)
    print(result)