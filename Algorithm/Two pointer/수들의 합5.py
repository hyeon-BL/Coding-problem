import sys
N = int(sys.stdin.readline())
start = 1
end = 1
count = 0

sum_value = 0
# Two-pointer
while end <= N:
    sum_value += end
    end += 1

    while sum_value > N and start < end:
        sum_value -= start
        start += 1

    if sum_value == N:
        count += 1
print(count)