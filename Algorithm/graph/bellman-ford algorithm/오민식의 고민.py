import sys
N, sc, ec, M = map(int, sys.stdin.readline().split())
edges = []
money = [-float('inf')] * N

for _ in range(M):
    u, v, w = map(int, sys.stdin.readline().split())
    edges.append((u, v, w))

incomes = list(map(int, sys.stdin.readline().split()))

money[sc] = incomes[sc]
for i in range(N + 100):
    for s, e, cost in edges:
        if money[s] == -float('inf'):
            continue
        elif money[s] == float('inf'):
            money[e] = float('inf')
        elif money[e] < money[s] + incomes[e] - cost:
            money[e] = money[s] + incomes[e] - cost
            if i > N - 1: # 양수 사이클 (ec가 사이클과 무관한 위치에 있을 수 있음 -> 100회 더 돌려서 cycle을 이루는 노드들 묶음)
                money[e] = float('inf')

if money[ec] == -float('inf'):
    print('gg')
elif money[ec] == float('inf'):
    print('Gee')
else:
    print(money[ec])