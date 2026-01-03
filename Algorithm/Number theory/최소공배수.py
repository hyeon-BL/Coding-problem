import sys
T = int(sys.stdin.readline())

def gcd(a, b):
    if a % b == 0:
        return b
    else:
        return gcd(b, a % b)

def lcm(a, b):
    return a * b // gcd(a, b)

while T > 0:
    A, B = map(int, sys.stdin.readline().split())
    print(lcm(A, B))
    T -= 1