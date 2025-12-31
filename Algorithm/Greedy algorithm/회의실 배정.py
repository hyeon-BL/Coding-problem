import sys
N = int(sys.stdin.readline())
meetings = []
for _ in range(N):
    s_t, e_t = map(int, sys.stdin.readline().split())
    meetings.append((e_t, s_t))
meetings.sort()

end = -1
cnt = 0
for meeting in meetings:
    if meeting[1] >= end:
        end = meeting[0]
        cnt += 1
print(cnt)