import sys
N = int(sys.stdin.readline().rstrip())

base = 362880 # 9!
result = base
for i in range(10, N + 1):
    result *= i
    while result % 10 == 0:
        result //= 10
    result %= 10**11
else:
    result %= 100000
print(str(result).zfill(5))