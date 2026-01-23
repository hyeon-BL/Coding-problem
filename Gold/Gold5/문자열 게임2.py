import sys
T = int(sys.stdin.readline())
for _ in range(T):
    alphabet = {}
    W = sys.stdin.readline()
    for i, s in enumerate(W):
        if s not in alphabet:
            alphabet[s] = [i]
        else:
            alphabet[s].append(i)
    
    K = int(sys.stdin.readline())
    minL = float('inf')
    maxL = -1

    for alpha, lst in alphabet.items():
        if len(lst) >= K:
            start = 0
            end = K - 1
            while end < len(lst):
                minL = min(alphabet[alpha][end] - alphabet[alpha][start] + 1, minL)
                maxL = max(alphabet[alpha][end] - alphabet[alpha][start] + 1, maxL)
                start += 1
                end += 1
    if minL == float('inf') or maxL == -1:
        print(-1)
    else:
        print(minL, maxL)
