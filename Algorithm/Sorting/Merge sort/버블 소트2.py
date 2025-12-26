import sys
N = int(sys.stdin.readline())
arr = list(map(int, sys.stdin.readline().split()))
result = 0

def merge_sort(arr):
    global result
    if len(arr) <= 1:
        return arr
    mid = len(arr) // 2
    left = merge_sort(arr[:mid])
    right = merge_sort(arr[mid:])
    
    merged = []
    i = j = 0
    while i < len(left) and j < len(right):
        if left[i] <= right[j]:
            merged.append(left[i])
            i += 1
        else: # left[i] > right[j]
            merged.append(right[j])
            result += len(left) - i # 왼쪽 배열에 남아있는 원소의 개수만큼 더해줌 -> swap 횟수
            j += 1
    merged.extend(left[i:])
    merged.extend(right[j:])
    return merged

merge_sort(arr)
print(result)