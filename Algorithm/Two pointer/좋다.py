import sys
N = int(sys.stdin.readline())
A = list(map(int, sys.stdin.readline().split()))
A.sort()

good_count = 0
for num in range(N):
    target = A[num]
    start, end = 0, N - 1

    # Two-pointer
    while start < end:
        if start == num:
            start += 1
            continue
        if end == num:
            end -= 1
            continue

        current_sum = A[start] + A[end]

        if current_sum == target:
            good_count += 1
            break
        elif current_sum < target:
            start += 1
        else:
            end -= 1
print(good_count)



''' 배열에 같은 수가 존재하면 correctness를 보장하지 못함
eg. A = [0 1 1]에서 A[0] + A[2] = A[1]의 반례 존재 

if N < 3:
    print(0)
    sys.exit()

good_count = 0
for num in range(2, N):
    target = A[num]
    start, end = 0, num - 1

    # Two-pointer
    while start < end:
        current_sum = A[start] + A[end]

        if current_sum == target:
            good_count += 1
            break
        elif current_sum < target:
            start += 1
        else:
            end -= 1

'''