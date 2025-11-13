import sys
N, M = map(int, sys.stdin.readline().split())
total_length = 0
words = []
for _ in range(N):
    words.append(sys.stdin.readline().strip())
    total_length += len(words[-1])
needed_length = M - total_length

additional_words = [needed_length // (N - 1)] * (N - 1)
remainder = needed_length % (N - 1)
for i in range(1, N):
    if words[i][0] >= 'a' and words[i][0] <= 'z':
        if remainder > 0:
            additional_words[i - 1] += 1
            remainder -= 1
for i in range(N - 1, 1, -1):
    if words[i][0] >= 'A' and words[i][0] <= 'Z':
        if remainder > 0:
            additional_words[i - 1] += 1
            remainder -= 1
for i in range(N):
    if i == 0:
        print(words[i], end='')
    else:
        print('_' * additional_words[i - 1] + words[i], end='')