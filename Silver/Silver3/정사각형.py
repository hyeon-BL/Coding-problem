import sys
import math

def distance(p1, p2):
    return (p1[0] - p2[0]) ** 2 + (p1[1] - p2[1]) ** 2

N = int(sys.stdin.readline())

for _ in range(N):
    points = [tuple(map(int, sys.stdin.readline().split())) for _ in range(4)]
    (x1, y1), (x2, y2), (x3, y3), (x4, y4) = points

    distances = [
        distance(points[0], points[1]),
        distance(points[0], points[2]),
        distance(points[0], points[3]),
        distance(points[1], points[2]),
        distance(points[1], points[3]),
        distance(points[2], points[3]),
    ]
    distances.sort()

    if distances[0] == distances[1] == distances[2] == distances[3] and distances[4] == distances[5] and distances[0] < distances[4]:
        print(1)
    else:
        print(0)


