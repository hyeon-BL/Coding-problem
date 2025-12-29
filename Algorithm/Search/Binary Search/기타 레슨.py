import sys
N, M = map(int, sys.stdin.readline().split())
A = list(map(int, sys.stdin.readline().split()))

start = -1 # 최댓값
end = 0    # 총합
for i in A:
    start = max(start, i)
    end += i

while start <= end:
    mid = (start + end) // 2
    sum = 0
    cnt = 0
    for i in A:
        if sum + i > mid:
            cnt += 1
            sum = 0
        sum += i
    if sum:
        cnt += 1

    if cnt > M: # 블루레이 크기 키우기
        start = mid + 1
    else:       # 블루레이 크기 줄이기
        end = mid - 1

print(start)