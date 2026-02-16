import sys
import bisect

N = int(sys.stdin.readline())
A = list(map(int, sys.stdin.readline().split()))

def binary_search(start, end, target):
    while (start <= end):
        mid = (start + end) // 2
        
        if lis[mid] >= target:
            end = mid - 1
        else:
            start = mid + 1
    return start

lis = []
for ele in A:
    if not lis or lis[-1] < ele:
        lis.append(ele)
    else:
        # idx = bisect.bisect_left(lis, ele)
        idx = binary_search(0, len(lis) - 1, ele)
        lis[idx] = ele

print(len(lis))