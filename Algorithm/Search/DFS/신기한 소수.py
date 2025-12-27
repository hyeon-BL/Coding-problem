import sys
sys.setrecursionlimit(10000)

N = int(sys.stdin.readline())

def find_prime(num):
    target = int(num)
    for i in range(2, target//2+1):
        if target % i == 0:
            return False
    else:
        return True

def dfs(num):
    if len(num) == N:
        print(num)
        return
    for i in range(1, 10, 2):
        if find_prime(num + str(i)):
            dfs(num + str(i))

for i in [2, 3, 5, 7]:
    dfs(str(i))