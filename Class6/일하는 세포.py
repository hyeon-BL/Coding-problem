import sys
T, N, D = map(int, sys.stdin.readline().split())
adj = [[[0] * N for _ in range(N)] for _ in range(T)]
MOD = 1_000_000_007
for i in range(T):
    M = int(sys.stdin.readline())
    for _ in range(M):
        a, b, c = map(int, sys.stdin.readline().split())
        adj[i][a - 1][b - 1] = c

def mul_matrix(mat1, mat2, size): # 크기가 size인 두 정사각 행렬 mat1과 mat2를 곱하여 반환
    res = [[0] * size for _ in range(size)]
    for i in range(size):
        for k in range(size):
            if mat1[i][k] == 0:
                continue
            for j in range(size):
                res[i][j] = (res[i][j] + mat1[i][k] * mat2[k][j]) % MOD
    return res

def power_matrix(mat, p, size): # 행렬 mat을 p번 거듭제곱한 결과를 분할 정복으로 구함
    res = [[0] * size for _ in range(size)]
    for i in range(size):
        res[i][i] = 1
        
    base = mat
    
    while p > 0:
        if p % 2 == 1:
            res = mul_matrix(res, base, size)
        base = mul_matrix(base, base, size)
        p //= 2
        
    return res

# 기본 단위 행렬
base = [[0] * N for _ in range(N)]
for i in range(N):
    base[i][i] = 1

# Period: T초(1주기) 동안의 변화
for i in range(T):
    base = mul_matrix(base, adj[i], N)

# 전체 D초 중 가능한 주기(몫)만큼 거듭제곱, 나머지만큼 추가로 곱함
res = power_matrix(base, D // T, N)
for i in range(D % T):
    res = mul_matrix(res, adj[i], N)

for row in res:
    print(*row)