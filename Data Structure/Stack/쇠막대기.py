import sys
arrange = sys.stdin.readline().strip()
stack = []

pipe = 0
result = 0
for i, char in enumerate(arrange):
    if char == '(':
        stack.append(char)
        pipe += 1
    else:
        stack.pop()
        pipe -= 1
        if arrange[i - 1] == '(':  # 레이저인 경우
            result += pipe
        else:  # 쇠막대기의 끝인 경우
            result += 1
print(result)