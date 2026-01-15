import sys
N = int(sys.stdin.readline())
channels = [sys.stdin.readline().rstrip() for _ in range(N)]

cnt1 = channels.index('KBS1')
channels = ['KBS1'] + channels[:cnt1] + channels[cnt1+1:]
cnt2 = channels.index('KBS2')
print('1' * cnt1, '4' * cnt1, '1' * cnt2, '4' *  (cnt2 - 1), sep='')