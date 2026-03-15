import sys
import math
X, Y, C = map(float, sys.stdin.readline().split())
ERROR = 1e-6

def binary_search(mi, ma):
    while (ma - mi) > ERROR:
        mid = (mi + ma) / 2

        a = math.sqrt(max(0.0, Y * Y - mid * mid))
        b = math.sqrt(max(0.0, X * X - mid * mid))
        est_c = (a * b) / (a + b)
        if abs(est_c - C) < ERROR:
            return mid

        if est_c > C:
            mi = mid
        else:
            ma = mid
    return (mi + ma) / 2

print(binary_search(0, min(X, Y)))