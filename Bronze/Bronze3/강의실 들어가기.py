import sys
cur = list(map(int, sys.stdin.readline().split(":")))
lec = list(map(int, sys.stdin.readline().split(":")))
t, k = map(int, sys.stdin.readline().split())
HOUR = 3600
MIN = 60

cur_s = HOUR * cur[0] + MIN * cur[1] + cur[2]
lec_s = HOUR * lec[0] + MIN * lec[1] + lec[2]
if t * (100 - k) / 100 + cur_s > lec_s:
    print(0)
else:
    print(1)