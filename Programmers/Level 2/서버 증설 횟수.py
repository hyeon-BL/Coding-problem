def solution(players, m, k):
    answer = 0
    for i in range(len(players)):
        players[i] = players[i] // m
    server = [0] * len(players)
    start = 0
    while start < len(players):
        if server[start] < players[start]:
            initial = server[start]
            answer += players[start] - initial
            for i in range(start, min(start + k, len(players))):
                server[i] += players[start] - initial
        start += 1

print(solution([0, 2, 3, 3, 1, 2, 0, 0, 0, 0, 4, 2, 0, 6, 0, 4, 2, 13, 3, 5, 10, 0, 1, 5],3,5))