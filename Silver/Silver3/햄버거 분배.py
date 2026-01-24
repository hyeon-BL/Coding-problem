import sys
from collections import deque
N, K = map(int, sys.stdin.readline().split())
s = sys.stdin.readline()

people = deque()
burgers = deque()

for i in range(N):
    if s[i] == 'P':
        people.append(i)
    elif s[i] == 'H':
        burgers.append(i)

cnt = 0
while people and burgers:
    person = people[0]
    burger = burgers[0]

    if abs(person - burger) <= K:
        cnt += 1
        people.popleft()
        burgers.popleft()
    elif burger < person:
        burgers.popleft()
    else:
        people.popleft()

print(cnt)
    