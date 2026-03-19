import sys
import heapq

N = int(sys.stdin.readline())

lectures = []
for _ in range(N):
    start, end = map(int, sys.stdin.readline().split())
    lectures.append((start, end))
    
lectures.sort()

# 회의실의 종료 시간 저장
room_ends = []
heapq.heappush(room_ends, lectures[0][1])

for i in range(1, N):
    if lectures[i][0] >= room_ends[0]:
        # 기존 강의실 그대로 사용
        heapq.heappop(room_ends)
    
    heapq.heappush(room_ends, lectures[i][1]) # 새 강의실 추가 or 끝나는 시간 업데이트

print(len(room_ends))

"""
heapq는 일반 리스트를 이용하기 때문에 **단순히 배열이름[0]으로 접근하는 것만으로 
요소를 빼지 않고 가장 작은 원소를 O(1) 시간에 바로 확인(Peek)**할 수 있습니다.
"""