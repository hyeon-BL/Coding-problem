import sys
N = int(sys.stdin.readline().rstrip())
arr = [sys.stdin.readline().rstrip() for _ in range(N)]


# 가로로 누울 수 있는 경우
width_count = 0
for i in range(N):
    straight_count = 0
    for j in range(N):
        if arr[i][j] == '.':
            straight_count += 1
        else:
            if straight_count >= 2:
                width_count += 1
            straight_count = 0
    if straight_count >= 2:
        width_count += 1
        

# 세로로 누울 수 있는 경우
height_count = 0
for j in range(N):
    straight_count = 0
    for i in range(N):
        if arr[i][j] == '.':
            straight_count += 1
        else:
            if straight_count >= 2:
                height_count += 1
            straight_count = 0
    if straight_count >= 2:
        height_count += 1

print(width_count, height_count)