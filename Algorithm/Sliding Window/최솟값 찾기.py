import sys
from collections import deque
N, L = map(int, sys.stdin.readline().split())
numbers = list(map(int, sys.stdin.readline().split()))

Range_L = deque()
for i in range(N):
    # 새로운 수가 들어올 때, 덱의 뒤쪽에서부터 비교하여
    # 덱에 있는 수보다 작으면 덱에서 제거
    while Range_L and Range_L[-1][0] > numbers[i]:
        Range_L.pop()
    # 현재 수와 인덱스를 덱에 추가
    Range_L.append((numbers[i], i))

    # 덱의 앞쪽에서 윈도우 범위를 벗어난 수 제거
    if Range_L[0][1] <= i - L:
        Range_L.popleft()

    # 현재 윈도우의 최솟값 출력
    print(Range_L[0][0], end=' ')