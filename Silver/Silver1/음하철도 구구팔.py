def gcd(a, b):
    while b:
        a, b = b, a % b
    return a

xs, xy = map(int, input().split())
xe, ye, dx, dy = map(int, input().split())

positions = [(xe, ye)]
d = gcd(abs(dx), abs(dy))
dx //= d
dy //= d
while (xe <= 100 and ye <= 100):
    xe += dx 
    ye += dy
    positions.append((xe, ye))

closest_pos = None
min_dist = float('inf')

for pos in positions:
    dist = (pos[0] - xs) ** 2 + (pos[1] - xy) ** 2
    if dist < min_dist:
        min_dist = dist
        closest_pos = pos

print(closest_pos[0], closest_pos[1])