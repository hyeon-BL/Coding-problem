import sys
dots = [tuple(map(int, sys.stdin.readline().split())) for _ in range(3)]

def CCW(dot1, dot2, dot3):
    res = (dot1[0] * dot2[1] + dot2[0] * dot3[1] + dot3[0] * dot1[1]) \
            - (dot2[0] * dot1[1] + dot3[0] * dot2[1] + dot1[0] * dot3[1])
    if res > 0:
        return 1
    elif res < 0:
        return -1
    return 0

print(CCW(dots[0], dots[1], dots[2]))