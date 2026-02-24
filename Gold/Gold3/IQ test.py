import sys
N = int(sys.stdin.readline())
arr = list(map(int, sys.stdin.readline().split()))

def is_all_equal():
    num = arr[0]
    for ele in arr:
        if ele != num:
            return False
    else:
        return True

if N == 2 and arr[0] == arr[1]:
    print(arr[0])
    sys.exit()
elif N <= 2:
    print('A')
    sys.exit()

res = (-1, -1)
cnt = 0
for mul in range(-201, 201):
    plus = arr[1] - arr[0] * mul
    for i in range(N - 1):
        if arr[i + 1] != arr[i] * mul + plus:
            break
    else:
        cnt += 1
        res = (mul, plus)

if res == (-1, -1):
    print('B')
elif is_all_equal():
    print(arr[0])
elif cnt != 1:
    print('A')
else:
    print(arr[-1] * res[0] + res[1])