import sys
expression = sys.stdin.readline()
minus = expression.split('-')

min_val = 0
for i, temp in enumerate(minus):
    plus = map(int, temp.split('+'))
    for num in plus:
        if i == 0:
            min_val += num
        else:
            min_val -= num

print(min_val)