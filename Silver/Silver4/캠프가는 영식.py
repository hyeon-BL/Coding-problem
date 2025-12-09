import sys
N, T = map(int, sys.stdin.readline().split())
buses = dict()
for i in range(N):
    start, interval, count = map(int, sys.stdin.readline().split())
    buses[i] = (start, interval, count)

min_wait = float('inf')
for start, interval, count in buses.values():
    for k in range(count):
        departure_time = start + k * interval
        if departure_time >= T:
            wait_time = departure_time - T
            if wait_time < min_wait:
                min_wait = wait_time
            break
if min_wait == float('inf'):
    print(-1)
else:
    print(min_wait)