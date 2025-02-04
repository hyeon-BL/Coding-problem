'''
수학 : 절댓값의 합의 최솟값을 구하는 문제
=> 중앙값을 더했을 때 최솟값이 나온다.
'''


N = int(input())
arr = []

for i in range(N):
    arr.append(list(map(int, input().split())))

AB = sorted([a-b for a, b in arr])
if (N % 2 == 0):
    print(abs((AB[N//2-1])-(AB[N//2]))+1)
else:
    print(1)