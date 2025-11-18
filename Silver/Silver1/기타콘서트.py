import sys

def find_min_guitars(guitars, M, idx, played, count):
    global min_count
    global most_notes

    # 최대한 많은 음을 연주한 경우
    if bin(played).count('1') > bin(most_notes).count('1'):
        most_notes = played
        min_count = count

    # 동일한 음을 연주했지만 기타 수가 더 적은 경우
    elif bin(played).count('1') == bin(most_notes).count('1') and bin(played).count('1') != 0:
        min_count = min(min_count, count)

    # 기타를 모두 확인한 경우
    if idx == len(guitars):
        return

    # 현재 기타를 선택하지 않는 경우
    find_min_guitars(guitars, M, idx + 1, played, count)

    # 현재 기타를 선택하는 경우
    find_min_guitars(guitars, M, idx + 1, played | guitars[idx][1], count + 1)

N, M = map(int, sys.stdin.readline().split())
guitars = []
for _ in range(N):
    name, music = sys.stdin.readline().split()
    bitmask = 0
    for i, note in enumerate(music):
        if note == 'Y':
            bitmask |= (1 << i)
    guitars.append((name, bitmask))

min_count = float('inf')
most_notes = 0
find_min_guitars(guitars, M, 0, 0, 0)
print(min_count if min_count != float('inf') else -1)