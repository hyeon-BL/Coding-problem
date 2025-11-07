import sys
N, C, W = map(int, sys.stdin.readline().split())
items = []
max_length = 0
for _ in range(N):
    items.append(int(sys.stdin.readline()))
    max_length = max(max_length, items[-1])

max_profit = 0
for length in range(1, max_length + 1): # length 기준으로 자르기
    temp_profit = 0
    for item in items: # 각 item에 대해
        cost = 0
        if item % length: 
            cost = C * (item // length)
        else: 
            cost = C * (item // length - 1)
        if (item // length) * length * W - cost > 0:
            temp_profit += (item // length) * length * W - cost
    max_profit = max(max_profit, temp_profit)
    # print(f'length: {length}, profit: {temp_profit}') for debugging
print(max_profit)