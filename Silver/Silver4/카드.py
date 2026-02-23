import sys
N = int(sys.stdin.readline())
cards = {}
for _ in range(N):
    card = int(sys.stdin.readline())
    if card in cards:
        cards[card] += 1
    else:
        cards[card] = 1
print(max(cards, key=lambda x: (cards[x], -x)))