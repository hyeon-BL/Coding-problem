import heapq

def solution(jobs):
    jobs.sort(key=lambda x: x[0])
    
    pq = []
    time, cum, i = 0, 0, 0
    n = len(jobs)
    
    while i < n or pq:
        while i < n and jobs[i][0] <= time:
            heapq.heappush(pq, (jobs[i][1], jobs[i][0])) # (소요시간, 요청시간)
            i += 1
        
        if pq:
            duration, arrival = heapq.heappop(pq)
            time += duration
            cum += (time - arrival) # (종료시간 - 요청시간) = 반환시간
        else:
            time = jobs[i][0]
            
    return cum // n