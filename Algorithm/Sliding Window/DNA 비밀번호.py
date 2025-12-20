import sys
S, P = map(int, sys.stdin.readline().split())
DNA = sys.stdin.readline().strip()
required = list(map(int, sys.stdin.readline().split()))

current_count = [0, 0, 0, 0]  # A, C, G, T
result = 0

def check():
    for i in range(4):
        if current_count[i] < required[i]:
            return False
    return True

start = 0
end = P - 1

# 초기 윈도우 설정
for i in range(P):
    if DNA[i] == 'A':
        current_count[0] += 1
    elif DNA[i] == 'C':
        current_count[1] += 1
    elif DNA[i] == 'G':
        current_count[2] += 1
    elif DNA[i] == 'T':
        current_count[3] += 1
if check():
    result += 1

while end < S - 1:
    # 윈도우 이동
    if DNA[start] == 'A':
        current_count[0] -= 1
    elif DNA[start] == 'C':
        current_count[1] -= 1
    elif DNA[start] == 'G':
        current_count[2] -= 1
    elif DNA[start] == 'T':
        current_count[3] -= 1

    start += 1
    end += 1

    if DNA[end] == 'A':
        current_count[0] += 1
    elif DNA[end] == 'C':
        current_count[1] += 1
    elif DNA[end] == 'G':
        current_count[2] += 1
    elif DNA[end] == 'T':
        current_count[3] += 1

    if check():
        result += 1
print(result)