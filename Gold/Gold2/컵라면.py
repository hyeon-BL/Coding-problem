import sys
import heapq
N = int(sys.stdin.readline())
pq = []
for _ in range(N):
	eta, num = map(int, sys.stdin.readline().split())
	heapq.heappush(pq, (eta, -num))

gains = []
t = 0
while len(pq) > 0:
	eta, num = heapq.heappop(pq)

	if eta > t:
		gains.append(-num)
		t += 1
	elif eta == t and -num > min(gains):
		gains.pop(gains.index(min(gains)))
		gains.append(-num)
print(sum(gains))
