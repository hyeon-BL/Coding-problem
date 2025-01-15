N, K = map(int, input().split())
arr = list(map(int, input().split(',')))

def sequence_change(arr):
    result = []
    for i in range(1, len(arr)):
        result.append(arr[i] - arr[i-1])
    return result

for i in range(K):
    arr = sequence_change(arr)

print(','.join(map(str, arr)))
        