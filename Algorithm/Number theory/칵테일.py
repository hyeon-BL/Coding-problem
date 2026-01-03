import sys
N = int(sys.stdin.readline())
ingredients = [[] for _ in range(N)]
vals = [-1 for _ in range(N)]
lcm = 1

def gcd(a, b):
    if a % b == 0:
        return b
    else:
        return gcd(b, a % b)

def dfs(start):
    for next, p, q in ingredients[start]:
        if vals[next] == -1:
            vals[next] = vals[start] * q // p
            dfs(next)

for _ in range(N - 1):
    a, b, p, q = map(int, sys.stdin.readline().split())
    ingredients[a].append((b, p, q))
    ingredients[b].append((a, q, p))
    lcm = lcm * p * q // gcd(p, q)


vals[0] = lcm
dfs(0)

divider = lcm
for i in range(N):
    divider = gcd(divider, vals[i])

for needed in vals:
    print(needed // divider, end=' ')
