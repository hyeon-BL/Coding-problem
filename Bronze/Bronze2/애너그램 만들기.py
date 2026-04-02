import sys
word1 = sys.stdin.readline().rstrip()
word2 = sys.stdin.readline().rstrip()
alpha1 = {}
alpha2 = {}
for e in word1:
    if e in alpha1:
        alpha1[e] += 1
    else:
        alpha1[e] = 1
for e in word2:
    if e in alpha2:
        alpha2[e] += 1
    else:
        alpha2[e] = 1
cnt = 0
for uni in range(ord('a'), ord('z') + 1):
    alpha = chr(uni)
    if alpha in alpha1 and alpha in alpha2:
        cnt += abs(alpha1[alpha] - alpha2[alpha])
    elif alpha in alpha1:
        cnt += alpha1[alpha]
    elif alpha in alpha2:
        cnt += alpha2[alpha]
print(cnt)
