import sys
import heapq

L = int(sys.stdin.readline().rstrip())
if L > 0:
    S = list(map(int, sys.stdin.readline().split()))
else:
    S = []
n = int(sys.stdin.readline().rstrip())

S.sort()
pq = []  # Min Heap
visited = set()  # 중복 방지

def get_sector_count(num, part):
    left = 1
    right = 0
    
    # 해당 파트의 경계값인 경우 (S에 포함된 수)
    if part < L and S[part] == num:
        return 0
        
    if part == 0:
        right = S[0] - 1
    elif part == L:
        return -1
    else:
        left = S[part - 1] + 1
        right = S[part] - 1
    
    # 경계값 밖인 경우
    if num < left or num > right:
        return -1
        
    return (num - left + 1) * (right - num + 1) - 1

for i in range(L):
    if i == 0:
        left = 1
        right = S[0]
    else:
        left = S[i - 1]
        right = S[i]

    # 왼쪽에서 오른쪽으로 스캔
    count = 0
    for j in range(left, right + 1):
        if count >= n:
            break
        
        if j not in visited:
            cnt = get_sector_count(j, i)
            visited.add(j)
            priority_val = cnt if cnt != -1 else float('inf')
            heapq.heappush(pq, (priority_val, j))
        count += 1

    # 오른쪽에서 왼쪽으로 스캔
    count = 0
    for j in range(right, left - 1, -1):
        if count >= n:
            break
            
        if j not in visited:
            cnt = get_sector_count(j, i)
            visited.add(j)
            priority_val = cnt if cnt != -1 else float('inf')
            heapq.heappush(pq, (priority_val, j))
        count += 1

# S의 최대값보다 큰 수들 처리
for i in range(1, n + 1):
    val = S[L - 1] + i
    heapq.heappush(pq, (float('inf'), val))

# 결과 출력
results = []
for _ in range(n):
    if pq:
        score, num = heapq.heappop(pq)
        results.append(str(num))
print(' '.join(results))