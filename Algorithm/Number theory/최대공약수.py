import sys
def gcd(a, b):
    if a % b == 0:
        return b
    else:
        return gcd(b, a % b)
    
A_count1, B_count1 = map(int, sys.stdin.readline().split())
print('1' * gcd(A_count1, B_count1))