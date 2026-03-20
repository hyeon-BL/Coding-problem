import sys
S = sys.stdin.readline().rstrip()
alpha = {}
for i in range(ord('a'), ord('z') + 1):
    alpha[i] = 0
for e in S:
    alpha[ord(e)] += 1
for i in range(ord('a'), ord('z') + 1):
    print(alpha[i], end=' ')


"""
더 명시적인 방법
chr => 유니코드를 문자로
ord => 문자를 유니코드로

s = input().strip()
counts = [s.count(chr(i)) for i in range(97, 123)]
print(*counts)
"""