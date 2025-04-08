import re
import sys
num = int(sys.stdin.readline())


def AC(p, n, lst):
    r=0
    region = 0
    for i in p:
        if i == 'R':
            r += 1
        else:
            if not lst:
                print('error')
                break
            else:
                lst.pop(region)
        if r % 2 == 1:
            region = -1
        else:
            region = 0
    if r % 2 == 1:
        lst.reverse()
    print([int(i) for i in lst])
    

for _ in range(num):
    p = sys.stdin.readline().rstrip()
    n = int(sys.stdin.readline())
    lst = sys.stdin.readline().rstrip()
    lst = re.findall('\d+', lst)
    AC(p, n, lst)
