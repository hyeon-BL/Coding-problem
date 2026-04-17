import sys
A, B = map(int, sys.stdin.readline().split())
arrA = set(map(int, sys.stdin.readline().split()))
arrB = set(map(int, sys.stdin.readline().split()))

diff = sorted(arrA.difference(arrB))
print(len(diff))
print(*diff)