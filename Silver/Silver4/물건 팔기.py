import sys
N = int(sys.stdin.readline())
elements = []
for _ in range(N):
    price, cost = map(int, sys.stdin.readline().split())
    elements.append((price, cost))
elements.sort(key=lambda x: (x[0], x[1]))
max_profit = 0
best_price = 0
for i in range(N):
    total_profit = 0
    for j in range(i, N):
        profit = elements[i][0] - elements[j][1]
        if profit > 0:
            total_profit += profit
    if (total_profit > max_profit) or (total_profit == max_profit and elements[i][0] < best_price):
        max_profit = total_profit
        best_price = elements[i][0]

if max_profit <= 0:
    print(0)
else:
    print(best_price)