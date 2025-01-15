num = int(input())

gm = 4
for i in range(1, num+1):
    value = str(i)
    for j in value:
        if j not in ['4', '7']:
            break
    else:
        gm = i

print(gm)