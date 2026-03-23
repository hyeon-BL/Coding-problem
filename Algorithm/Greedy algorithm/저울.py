import sys
N = int(sys.stdin.readline())
arr = list(map(int, sys.stdin.readline().split()))
arr.sort()

def lower(num):
    s = 0
    e = len(candidates) - 1
    while s < e:
        mid = (s + e) // 2
        if candidates[mid] > num:
            e = mid
        else:
            s = mid + 1

    val = candidates[s - 1] if s != 0 and candidates[s] > num else candidates[s]
    candidates.remove(val)
    return val

for i in range(1, 1001): # https://aerocode.net/392 -> sigma(2^N)까지 가능하다...
    temp = i
    candidates = arr.copy()
    while temp > 0 and len(candidates) > 0:
        temp -= lower(temp)
    if temp < 0:
        print(i)
        break
    if len(candidates) == 0:
        print(i + 1)
        break


""" Solution
cum = 1
for i in range(N):
    if arr[i] > cum:
        break
    cum += arr[i]
print(cum)

"""