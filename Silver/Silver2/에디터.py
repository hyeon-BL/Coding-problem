import sys

input = sys.stdin.readline

# 커서 기준 왼쪽과 오른쪽을 스택으로 관리
left = list(input().rstrip('\n'))
M = int(input())
right = [] # 오른쪽은 가장 위 원소가 커서 바로 오른쪽 문자

for _ in range(M):
    cmd = input().split()
    if cmd[0] == 'L':
        if left:
            right.append(left.pop())
    elif cmd[0] == 'D':
        if right:
            left.append(right.pop())
    elif cmd[0] == 'B':
        if left:
            left.pop()
    else:  # 'P'
        left.append(cmd[1])

sys.stdout.write(''.join(left + right[::-1]))