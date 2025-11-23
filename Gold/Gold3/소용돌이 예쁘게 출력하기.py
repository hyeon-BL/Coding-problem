import sys

# 소용돌이 패턴에서 좌표 (x, y)의 값을 계산하는 함수
def calculate_value(x, y):
    layer = max(abs(x), abs(y))  # 현재 좌표가 속한 소용돌이의 레이어
    max_value_in_layer = (2 * layer + 1) ** 2  # (layer, layer)

    if x == layer:  # bottom side (leftwards)
        return max_value_in_layer - (layer - y)
    elif y == -layer:  # left side (upwards)
        return max_value_in_layer - 2 * layer - (layer - x)
    elif x == -layer:  # top side (rightwards)
        return max_value_in_layer - 4 * layer - (y + layer)
    else:  # right side (downwards) y == layer
        return max_value_in_layer - 6 * layer - (x + layer)

r1, c1, r2, c2 = map(int, sys.stdin.readline().split())

# 소용돌이 패턴 계산
grid = []
max_value = 0
for i in range(r1, r2 + 1):
    row = []
    for j in range(c1, c2 + 1):
        value = calculate_value(i, j)
        row.append(value)
        if value > max_value:
            max_value = value  # 가장 큰 값 갱신
    grid.append(row)

max_length = len(str(max_value))

for row in grid:
    print(" ".join(f"{value:>{max_length}}" for value in row))
