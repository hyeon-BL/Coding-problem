import sys
A, B, C = map(int, sys.stdin.readline().split())

def gcd(a, b):
    if a % b == 0:
        return b
    else:
        return gcd(b, a % b)
    
def ext_euc(a, b):
    if b == 0:
        return (1, 0)
    q = a // b
    v = ext_euc(b, a % b)
    return (v[1], v[0] - v[1] * q)

if C % gcd(A, B) != 0:
    print(-1)
else:
    quotient = C // gcd(A, B)
    ret = ext_euc(A, B)
    print(ret[0] * quotient, ret[1] * quotient)