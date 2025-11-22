import sys
import math

min_num, max_num = map(int, sys.stdin.readline().split())
length = max_num - min_num + 1

# 제곱ㄴㄴ수를 체크하기 위한 배열 (True로 초기화)
is_square_free = [True] * length

# 2부터 √max_num까지의 제곱수 확인
for i in range(2, int(math.sqrt(max_num)) + 1):
    square = i * i  # 제곱수
    start = max(square, (min_num + square - 1) // square * square) # 제곱수의 배수 중 min_num 이상인 첫 번째 수
    for j in range(start, max_num + 1, square):
        is_square_free[j - min_num] = False # 제곱수의 배수는 제곱ㄴㄴ수가 아님

# True인 수 -> 제곱ㄴㄴ수의 개수
print(sum(is_square_free))