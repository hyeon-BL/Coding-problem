import sys
N, K = map(int, sys.stdin.readline().split())
A = list(map(int, sys.stdin.readline().split()))

def pick_pivot(start, end):
    mid = (start + end) // 2
    A[start], A[mid] = A[mid], A[start]
    pivot = A[start]
    i = start + 1
    j = end

    while i <= j:
        while i <= end and A[i] < pivot:
            i += 1
        while j >= start and A[j] > pivot:
            j -= 1
        if i < j:
            A[i], A[j] = A[j], A[i]
            i += 1
            j -= 1
        else:
            break
    A[start], A[j] = A[j], A[start]
    return j

def quick_sort(start, end, K):
    if start >= end:
        return
    pivot_index = pick_pivot(start, end)
    if pivot_index == K - 1:
        return
    elif pivot_index < K - 1:
        quick_sort(pivot_index + 1, end, K)
    else:
        quick_sort(start, pivot_index - 1, K)

quick_sort(0, N - 1, K)
print(A[K - 1])