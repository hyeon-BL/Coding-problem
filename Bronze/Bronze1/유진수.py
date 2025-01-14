num = input()

num1 = 1
num2 = 1

for i in range(1, len(num)+1):
    part1 = num[:i]
    part2 = num[i:]

    if len(num) == 1:
        print("NO")
        break

    for pn1 in part1:
        num1 *= int(pn1)
    for pn2 in part2:
        num2 *= int(pn2)

    if num1 == num2:
        print("YES")
        break
    else:
        num1 = 1
        num2 = 1
else:
    print("NO")