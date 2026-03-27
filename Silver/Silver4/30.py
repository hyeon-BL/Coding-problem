import sys
from itertools import permutations
N = list(sys.stdin.readline().rstrip())
N.sort(reverse=True)
res = N.copy()

if N[-1] != '0':
    print(-1)
    sys.exit()

for i in range(len(N) - 1, -1, -1):
    if N[i] in ['0', '3', '6', '9']:
        continue
    elif N[i] in ['2', '5', '8'] and i != 0:
        N[i - 1] = chr(ord(N[i - 1]) - 1)
        continue
    elif N[i] in ['4', '7'] and i != 0:
        N[i - 1] = chr(ord(N[i - 1]) - 2)
        continue
    elif N[i] == '1' and i != 0:
        temp = ord(N[i - 1]) - 2
        if chr(temp) >= '0':
            N[i - 1] = chr(temp)
        else:
            if i > 1:
                N[i - 2] = chr(ord(N[i - 2]) - 1)
                N[i - 1] = chr(temp + 10)
    else:
        print(-1)
        break
else:
    print(*res, sep='')