import sys
from collections import deque
N, K = map(int, sys.stdin.readline().split())
belt = deque(list(map(int, sys.stdin.readline().split())))
robots = deque([False] * N)

step = 1
while True:
    # 1. 벨트 회전
    belt.rotate(1)
    robots.rotate(1)
    robots[-1] = False

    # 2. 로봇 이동
    for i in range(N - 2, - 1, -1):
        if robots[i] == True:
            if not robots[i + 1] and belt[i + 1] > 0:
                robots[i] = False
                robots[i + 1] = True
                belt[i + 1] -= 1
    robots[-1] = False

    # 3. 로봇 올리기
    if not robots[0] and belt[0] > 0:
        robots[0] = True
        belt[0] -= 1

    # 4. 결과
    if belt.count(0) >= K:
        break
    else:
        step += 1

print(step)