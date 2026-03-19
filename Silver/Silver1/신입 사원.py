import sys

T = int(sys.stdin.readline())
for _ in range(T):
    N = int(sys.stdin.readline())
    
    grades = []
    for _ in range(N):
        grade = tuple(map(int, sys.stdin.readline().split()))
        grades.append(grade)
        
    grades.sort()

    cnt = 1 # 서류 1등은 무조건 합격
    prev_rank = grades[0][1]

    for i in range(1, N):
        if grades[i][1] < prev_rank:
            cnt += 1
            prev_rank = grades[i][1]

    print(cnt)
    T -= 1

"""
파이썬의 queue.PriorityQueue는 멀티 스레드 환경에서 안전하도록 설계되어(Thread-Safe) 내부적으로 Lock(락) 과정이 포함되어 있습니다.
이 때문에 단순 정렬이나 heapq에 비해 처리 속도가 무척 느리며, 알고리즘 문제에 사용하면 거의 무조건 시간 초과(TLE) 가 발생합니다.
"""