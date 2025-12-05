import sys
N = int(sys.stdin.readline().rstrip())
words = []
count = 0
for _ in range(N):
    word = sys.stdin.readline().rstrip()
    if word not in words:
        for i in range(len(word)):
            new_word = word[i:] + word[:i]
            words.append(new_word)
        count += 1
print(count)