king, stone, n = input().split()
king = [ord(king[0])-65, int(king[1])-1]
stone = [ord(stone[0])-65, int(stone[1])-1]
n = int(n)
order = []
for _ in range(n):
    order.append(input())

for o in order:
    if o == 'R':
        if king[0] == 7:
            continue
        if king[0] + 1 == stone[0] and king[1] == stone[1]:
            if stone[0] == 7:
                continue
            stone[0] += 1
        king[0] += 1
    elif o == 'L':
        if king[0] == 0:
            continue
        if king[0] - 1 == stone[0] and king[1] == stone[1]:
            if stone[0] == 0:
                continue
            stone[0] -= 1
        king[0] -= 1
    elif o == 'B':
        if king[1] == 0:
            continue
        if king[0] == stone[0] and king[1] - 1 == stone[1]:
            if stone[1] == 0:
                continue
            stone[1] -= 1
        king[1] -= 1
    elif o == 'T':
        if king[1] == 7:
            continue
        if king[0] == stone[0] and king[1] + 1 == stone[1]:
            if stone[1] == 7:
                continue
            stone[1] += 1
        king[1] += 1
    elif o == 'RT':
        if king[0] == 7 or king[1] == 7:
            continue
        if king[0] + 1 == stone[0] and king[1] + 1 == stone[1]:
            if stone[0] == 7 or stone[1] == 7:
                continue
            stone[0] += 1
            stone[1] += 1
        king[0] += 1
        king[1] += 1
    elif o == 'LT':
        if king[0] == 0 or king[1] == 7:
            continue
        if king[0] - 1 == stone[0] and king[1] + 1 == stone[1]:
            if stone[0] == 0 or stone[1] == 7:
                continue
            stone[0] -= 1
            stone[1] += 1
        king[0] -= 1
        king[1] += 1
    elif o == 'RB':
        if king[0] == 7 or king[1] == 0:
            continue
        if king[0] + 1 == stone[0] and king[1] - 1 == stone[1]:
            if stone[0] == 7 or stone[1] == 0:
                continue
            stone[0] += 1
            stone[1] -= 1
        king[0] += 1
        king[1] -= 1
    elif o == 'LB':
        if king[0] == 0 or king[1] == 0:
            continue
        if king[0] - 1 == stone[0] and king[1] - 1 == stone[1]:
            if stone[0] == 0 or stone[1] == 0:
                continue
            stone[0] -= 1
            stone[1] -= 1
        king[0] -= 1
        king[1] -= 1

print(chr(king[0]+65)+str(king[1]+1))
print(chr(stone[0]+65)+str(stone[1]+1))