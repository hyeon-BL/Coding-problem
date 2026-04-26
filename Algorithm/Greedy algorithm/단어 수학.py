import sys
n = int(sys.stdin.readline())
words = [sys.stdin.readline().strip() for _ in range(n)]

# 각 단어의 알파벳별 가중치 누적
alpha_weights = {}

for word in words:
    for i, char in enumerate(word):
        power = 10 ** (len(word) - 1 - i)
        alpha_weights[char] = alpha_weights.get(char, 0) + power

sorted_weights = sorted(alpha_weights.values(), reverse=True)

max_sum = 0
num = 9
for weight in sorted_weights:
    max_sum += weight * num
    num -= 1

print(max_sum)