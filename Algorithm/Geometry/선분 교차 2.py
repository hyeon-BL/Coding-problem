import sys
x1, y1, x2, y2 = map(int, sys.stdin.readline().split())
x3, y3, x4, y4 = map(int, sys.stdin.readline().split())

def CCW(dot1, dot2, dot3):
    res = (dot1[0] * dot2[1] + dot2[0] * dot3[1] + dot3[0] * dot1[1]) \
            - (dot2[0] * dot1[1] + dot3[0] * dot2[1] + dot1[0] * dot3[1])
    if res > 0:
        return 1
    elif res < 0:
        return -1
    return 0

def is_overlapped(dot1, dot2, dot3, dot4):
    if min(dot1[0], dot2[0]) <= max(dot3[0], dot4[0]) and min(dot3[0], dot4[0]) <= max(dot1[0], dot2[0]) \
        and min(dot1[1], dot2[1]) <= max(dot3[1], dot4[1]) and min(dot3[1], dot4[1]) <= max(dot1[1], dot2[1]):
        return 1
    else:
        return 0


def is_crossed(dot1, dot2, dot3, dot4):
    check1 = CCW(dot1, dot2, dot3) * CCW(dot1, dot2, dot4)
    check2 = CCW(dot3, dot4, dot1) * CCW(dot3, dot4, dot2)
    if check1 == 0 and check2 == 0:
        return is_overlapped(dot1, dot2, dot3, dot4)
    elif check1 <= 0 and check2 <= 0:
        return 1
    else:
        return 0

print(is_crossed((x1, y1), (x2, y2), (x3, y3), (x4, y4)))