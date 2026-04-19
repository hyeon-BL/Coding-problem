import sys
N = int(sys.stdin.readline())

seq = [3]
i = 2
while seq[-1] < N:
    seq.append(seq[-1] * 2 + (i + 2))
    i += 1

def solve(idx, n):
    if idx == 0:
        return 'm' if n == 1 else 'o'

    left = seq[idx - 1] # 이전 수열의 길이
    mid = idx + 3       # 중앙에 추가된 수열의 길이

    if n <= left:
        return solve(idx - 1, n)
    elif n <= left + mid:
        return 'm' if n - left == 1 else 'o'
    else:
        return solve(idx - 1, n - left - mid)


print(solve(len(seq) - 1, N))