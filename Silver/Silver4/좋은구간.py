L = int(input())
S = list(map(int, input().split()))
n = int(input())

S.sort()
for i in S[:-1]:
    next = S[S.index(i)+1]
    if n == i:
        print(0)
        exit()
    elif i < n < next:
        start = i+1
        end = next-1
        print((n-start)*(end-n+1) + (end-n))
        exit()
else:
    start = 1
    end = S[0]-1
    print((n-start)*(end-n+1) + (end-n))
