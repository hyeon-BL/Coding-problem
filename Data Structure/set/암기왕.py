import sys
T = int(sys.stdin.readline())
while T:
    N = int(sys.stdin.readline())
    notes = set(map(int, sys.stdin.readline().split()))
    M = int(sys.stdin.readline())
    compares = list(map(int, sys.stdin.readline().split()))
    for c in compares:
        if c in notes: # O(1) in set, dict / O(N) in list
            print(1)
        else:
            print(0)
    T -= 1