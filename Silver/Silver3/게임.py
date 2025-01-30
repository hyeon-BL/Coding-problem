def check(n):
    plusedZ = (Y + n) * 100 // (X + n)
    if Z < plusedZ:
        return True
    return False

def binary_search(): # 이진 탐색 O(logN)
    start = 0
    end = 1000000001
    result = 0
    while start <= end:
        mid = (start + end) // 2
        if check(mid):
            result = mid
            end = mid - 1
        else:
            start = mid + 1
    return result

X, Y = map(int, input().split())
Z = Y * 100 // X
print(binary_search() if Z < 99 else -1)



